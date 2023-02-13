/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:16:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/13 02:55:41 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing(char **env)
{
	int i = 0 ;
	char ** splitz;
	char *tmp;
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
		tmp = ft_strjoin(splitz[i],"/");
		free(splitz[i]);
		splitz[i] = tmp;
		i++;
	}
	return (splitz);
}

void	child_proc(int fd ,char* cmd1 , char** path , int *pip)
{
	int i  ;
	int err;
	char *fullpath;
	char ** cmds = ft_split(cmd1,' ');
	i = 0 ;
	dup2(fd, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	close(fd);
	while (path[i])
	{
		fullpath = ft_strjoin(path[i],cmds[0]);
		err = execve(fullpath,cmds,NULL);
		i++;
	}
	if (err == -1)
		perror("cant find the first command to execute");
}

void	parent_proc(int fd , char* cmd2 , char** path , int *pip)
{
	int i ;
	int err ;
	char *fullpath;
	char ** cmds = ft_split(cmd2,' ');
	i = 0;
	dup2(fd, STDOUT_FILENO);
	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
	close(fd);
	while (path[i])
	{
		fullpath = ft_strjoin(path[i],cmds[0]);
		err = execve(fullpath,cmds,NULL);
		i++;
	}
	if (err == -1)
		perror("cant find the second command to execute");
}

void	pipex(int *fd, char* cmd1, char* cmd2, char **env)
{
	char **path = parsing(env);

	int pip[2];
	pipe(pip);
	int pid1 = fork();
	if (pid1 == 0)
	{
		child_proc(fd[0], cmd1, path, pip);
	}
	if (pid1 != 0)
	{
		waitpid(pid1,NULL,0);
		parent_proc(fd[1], cmd2, path, pip);
	}
	wait(NULL);
}

// int main (int ac , char **av , char **env) 
// {
//     int fd[2];
//     if (ac != 5) {
//         printf("error passing above 4 args");
//         return -1;
//     }
//     fd[0] = open(av[1],O_RDONLY);
//     fd[1] = open(av[4],O_WRONLY | O_TRUNC | O_CREAT , 0644);
//     if (fd[0] < 0 || fd[1] < 0)
//     {
//         perror("Error opening W/R files");
//         return -2;
//     }
//     pipex(fd,av[2],av[3],env);
//     return 0;
// }

// int main (int ac ,char**av, char ** env)
// {
// 	char ** pars = parsing(env);   
// 	// while (1)
// 	//     sleep(1);
// }

// /* only this left is to handle pipe and get things working + make use of dub a must check accesibility nd last handling errors and norming*/