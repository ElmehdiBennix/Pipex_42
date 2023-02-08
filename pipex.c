/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 21:50:10 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int    pipex(int fd1, char* cmd1, char* cmd2, int fd2 , char* path) // for child processes / char *cmd1, outs put it to parent as input pipe to char *cmd2, to finish 
{
    // for process to child and parrent split the tasks so that the input for the child finishes as input for the parent to finish to simulate a pipe 
    //note / wait for child to finish the exec
    int i = 0;
    char ** res1 = ft_split(path,':');
    // char *tmp1 ;// = ft_strjoin(res1[i],ft_strjoin("/",res2[0])); // must add "/" res[0]      
    // char *tmp2 ;                                                                                                                     // while(res1[i])
                                                                                                                            // {
                                                                                                                            //     printf("%s\n",res1[i]);
                                                                                                                            //     i++;
                                                                                                                            // }
                                                                                                                            // printf("%s\n",res1[i]);
                                                                                                                            // i = 0;
                                                                                                                            // while(res2[i])
                                                                                                                            // {
                                                                                                                            //     printf("%s\n",res2[i]);
                                                                                                                            //     i++;
                                                                                                                            // }
                                                                                                                            // printf("%s\n",res2[i]);
    int pid = fork();
    if (pid == 0)
    {
        char ** res2 = ft_split(cmd1,' ');
        while(res1[i])
        {
            //dub2 redirect 
            char *tmp1 = ft_strjoin(res1[i],ft_strjoin("/",res2[0]));
            int err = execve(tmp1,res2,NULL);
            // if (err == -1)
            // {
            //     printf("cant find the command to execute");
            //     return -3;
            // }
            i++;
        }
    }
    else
    {
        i = 0;
        char ** res2 = ft_split(cmd2,' ');
        while(res1[i])
        {
            char *tmp2 = ft_strjoin(res1[i],ft_strjoin("/",res2[0]));
            int err = execve(tmp2,res2,NULL);
            // if (err == -1)
            // {
            //     printf("cant find the command to execute");
            //     return -4;
            // }
            i++;
        }
    }
    return 1;
}
int main (int ac , char **av , char **env) // 0 for a.out next for next in exec
{
    int fd[2];
    if (ac != 5) {
        printf("error passing above 4 args"); // gotta test that that perror
        return -1;
    }
    fd[0] = open(av[1],O_RDONLY);
    fd[1] = open(av[4],O_WRONLY | O_TRUNC); // o trunc to keep rewriting in outfile without commad output stacks
    if (fd[0] < 0 || fd[1] < 0) {
        perror("Error opening W/R files");
        return -2;
    }
    char * path = env[6] + 5;
    // printf("%s\n", path); // trunc PATH= and got the env for exev
    pipex(fd[0],av[2],av[3],fd[1],path);
}