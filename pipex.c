/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:16:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/11 15:21:27 by bennix           ###   ########.fr       */
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

int child_proc(int fd ,char* cmd1 , char** path , int *pip)
{
    int i = 0 ;
    int err;
    char ** cmds = ft_split(cmd1,' ');
    while(path[i])
    {
        dup2(fd, STDIN_FILENO);
	    dup2(pip[1], STDOUT_FILENO);
	    close(pip[0]);
        char *fullpath = ft_strjoin(path[i],cmds[0]);
        err = execve(fullpath,cmds,NULL);
        i++;
    }
    if (err == -1)
        perror("cant find the command to execute");
}

int parent_proc(int fd , char* cmd2 , char** path , int *pip)
{
    int i = 0;
    int err ;
    char ** cmds = ft_split(cmd2,' ');
	dup2(fd, STDOUT_FILENO);
    dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
    close(fd);
    while(path[i])
    {
        char *fullpath = ft_strjoin(path[i],cmds[0]);
        err = execve(fullpath,cmds,NULL);
        i++;
    }
    if (err == -1)
        perror("cant find the command to execute");
}

void    pipex(int *fd, char* cmd1, char* cmd2, char **env)
{
    int err;
    char ** path = parsing(env);
    int pip[2];
    pid_t pid = fork();

    if(pid < 0)
        return(perror("fork err"));

    if (pipe(pip) < 0)
        return(perror("pipe failed"));

    
    if (pid == 0)
    {
        err = child_proc(fd[0],cmd1,path,pip);
        if (err < 0)
            return(perror("error in child"));
    }
    else
    {
		wait(NULL);
        // tqke a look at the acces function 
        err = parent_proc(fd[1],cmd2,path,pip);
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
    fd[1] = open(av[4],O_WRONLY | O_TRUNC | O_CREAT , 0644);
    if (fd[0] < 0 || fd[1] < 0)
    {
        perror("Error opening W/R files");
        return -2;
    }
    pipex(fd,av[2],av[3],env);
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




/* only this left is to handle pipe and get things working + make use of dub a must check accesibility nd last handling errors and norming*/