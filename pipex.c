/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/08 15:32:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(int fd1, char* cmd1, char* cmd2, int fd2 , char* path) // for child processes / char *cmd1, outs put it to parent as input pipe to char *cmd2, to finish 
{
    // for process to child and parrent split the tasks so that the input for the child finishes as input for the parent to finish to simulate a pipe 
    //note / wait for child to finish the exec
    int i = 0;
    // char *tst= strdup(cmd1);
    char ** res = ft_split(path,':'); // must add "/" res[0]"
    char ** res2 = ft_split(cmd1,' ');
    // char * tmp1 = ft_strjoin("/",res2[0]);
    printf("%s\n",path);

    while(res[i])
    {
        printf("%s\n",res[i]);
        i++;
    }
    printf("%s\n",res[i]);
    i = 0;
    while(res2[i])
    {
        printf("%s\n",res2[i]);
        i++;
    }
    printf("%s\n",res2[i]);

    // char *tmp2 = ft_strjoin(res[i],tmp2);
    // printf("%s\n",tmp2);
    // while(res[i])
    // {

        // execve(tmp,res2,NULL); 
    // }
    
}
int main (int ac , char **av , char **env) // 0 for a.out next for next in exec
{
    int fd[2];
    // if (ac >= 6)
    // {
    //     printf("error passing above 4 args");
    //     return 1;
    // }
    fd[0] = open(av[1],O_RDONLY);
    fd[1] = open(av[4],O_WRONLY | O_TRUNC); // o trunc to keep rewriting in outfile without commad output stacks
    // if (fd[0] == -1 || fd[1] == -1) {
    //     perror("Error opening W/R files");
    //     return 1;
    // }
    char * path = env[6] + 5;
    // printf("%s\n", path); // trunc PATH= and got the env for exev
    pipex(fd[0],av[1],av[2],fd[1],path);
    return 0;
}