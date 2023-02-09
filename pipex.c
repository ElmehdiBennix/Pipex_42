/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/09 17:48:26 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *parsing(char **env)
{
    char * path = env[6] + 5; // need a parshing
    // printf("%s\n", path); // trunc PATH= and got the env for exev
}

int child_proc(int fd1 , char* cmd1 , char** res1)
{
    int i = 0 ;
    char ** res2 = ft_split(cmd1,' ');
    while(res1[i])
    {
        //dub2(fd1,stdin);
        char *tmp1 = ft_strjoin(res1[i],ft_strjoin("/",res2[0]));
        int err = execve(tmp1,res2,NULL);
        // if (err == -1)
        // {
        //     printf("cant find the command to execute");
        // }
        i++;
    }
}

int parent_proc(int fd2 , char* cmd2 , char** res1)
{
    int i = 0;
    char ** res2 = ft_split(cmd2,' ');
    while(res1[i])
    {
        //dub2();
        char *tmp2 = ft_strjoin(res1[i],ft_strjoin("/",res2[0]));
        int err = execve(tmp2,res2,NULL);
        // if (err == -1)
        // {
        //     printf("cant find the command to execute");
        // }
        i++;
    }
}

void    pipex(int fd1, char* cmd1, char* cmd2, int fd2 , char* path)
{
    // for process to child and parrent split the tasks so that the input for the child finishes as input for the parent to finish to simulate a pipe 
    //note -- wait for child to finish the exec
    int err;
    // cqll of parsing func better
    char** res = ft_split(path,':');
    pid_t pid = fork();
    if(pid < 0)
        return(perror("fork err"));
    if (pid == 0)
    {
        err = child_proc(fd1,cmd1,res);
        if (err < 0)
            return(perror("error in child"));
    }
    else
    {
        // wait for child procc to finish 
        // tqke a look at the acces function 
        err = parent_proc(fd2,cmd2,res);
        if (err < 0)
            return(perror("error in parent"));
    }
}
int main (int ac , char **av , char **env) 
{
    int fd[2];
    if (ac != 5) {
        printf("error passing above 4 args");
        return -1;
    }
    fd[0] = open(av[1],O_RDONLY);
    fd[1] = open(av[4],O_WRONLY | O_TRUNC);
    if (fd[0] < 0 || fd[1] < 0)
    {
        perror("Error opening W/R files");
        return -2;
    }
    char * path = env[6] + 5; // need a parshing
    // printf("%s\n", path); // trunc PATH= and got the env for exev
    pipex(fd[0],av[2],av[3],fd[1],path);
    return 0;
}