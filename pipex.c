/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:16:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/10 19:22:29 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char ** parsing(char **env)
{
    int i = 0 ;

    char ** splitz;
	char * path = NULL;
	while (env[i] && path == NULL)
	{
		path = ft_strnstr(env[i],"PATH=",5);
		i++;
	}
    splitz = ft_split(path + 5,':');
    i = 0;
    while (splitz[i])
    {
        splitz[i] = ft_strjoin(splitz[i],"/");
        i++;
    }
    return (splitz);
}

int child_proc(int fd1 , char* cmd1 , char** path)
{
    int i = 0 ;
    char ** cmds = ft_split(cmd1,' ');
    while(path[i])
    {
        //dup2(fd1,stdin);
        char *fullpath = ft_strjoin(path[i],cmds[0]);
        int err = execve(fullpath,cmds,NULL);
        if (err == -1)
            printf("cant find the command to execute");
        i++;
    }
}

int parent_proc(int fd2 , char* cmd2 , char** path)
{
    int i = 0;
    char ** cmds = ft_split(cmd2,' ');
    while(path[i])
    {
        //dup2();
        char *fullpath = ft_strjoin(path[i],cmds[0]);
        int err = execve(fullpath,cmds,NULL);
        if (err == -1)
            printf("cant find the command to execute");
        i++;
    }
}

void    pipex(int fd[2], char* cmd1, char* cmd2, char **env)
{
    int err;
    char ** path = parsing(env);
    pid_t pid = fork();

    if(pid < 0)
        return(perror("fork err"));

    if (pipe(fd[2]) < 0);
        return(perror("pipe failed"));

    
    if (pid == 0)
    {
        err = child_proc(fd[0],cmd1,path);
        if (err < 0)
            return(perror("error in child"));
    }
    else
    {
        wait(NULL); // pass var to check for errors
        // tqke a look at the acces function 
        err = parent_proc(fd[1],cmd2,path);
        if (err < 0)
            return(perror("error in parent"));
    }
}

int main (int ac , char **av , char **env) 
{
    int pid;
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
    pipex(fd[2],av[2],av[3],env);
    return 0;
}
// int main (int ac , char ** av , char ** env)
// {
//     char ** split=parsing(env);
//     int i = 0;
//     while (split[i])
//     {
//         printf("%s\n",split[i]);
//         i++;
//     }
//     printf("%s\n",split[i]);
// }





/* only this left is to handle pipe and get things working and add flags and
 rights to files for fds and check accesibility last handling errors and norming*/