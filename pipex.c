/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:16:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/13 04:08:50 by ebennix          ###   ########.fr       */
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

int	child_proc(int fd ,char* cmd1 , char** path , int *pip)
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
	while (path[i] && err == 0)
	{
		fullpath = ft_strjoin(path[i],cmds[0]);
		err = access(fullpath,X_OK);
		i++;
	}
	if (err == -1)
	{
		perror("cant find the first command to execute");
		return (err);
	}
	execve(fullpath,cmds,NULL);
}

int	parent_proc(int fd , char* cmd2 , char** path , int *pip)
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
	while (path[i] && err == 0)
	{
		fullpath = ft_strjoin(path[i],cmds[0]);
		err = access(fullpath,X_OK);
		i++;
	}
	if (err == -1)
	{
		perror("cant find the second command to execute");
		return (err);
	}
	execve(fullpath,cmds,NULL);
}

void	pipex(int *fd, char* cmd1, char* cmd2, char **env)
{
	char **path = parsing(env);
	int err;

	int pip[2];
	if (pipe(pip) == -1 )
	{
		perror("pipe failed");
        exit(EXIT_FAILURE);
    }
	int pid = fork();
	if(pid == -1)
	{
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
	if (pid == 0)
	{
		err = child_proc(fd[0], cmd1, path, pip);
		if (err == -1)
			exit(EXIT_FAILURE);
		
	}
	if (pid != 0)
	{
		waitpid(pid,NULL,0); ///CHECKKSSS
		err = parent_proc(fd[1], cmd2, path, pip);
		if (err == -1)
			exit(EXIT_FAILURE);
	}
	wait(NULL);   //CHECKKKSSS
}

int main (int ac , char **av , char **env) 
{
	int err;
    int fd[2];
    if (ac != 5)
        return (printf("error 4 arguments are required"));
	err = access(av[1],R_OK);
	err = access(av[4],W_OK | R_OK );
	if (err = -1)
		return (printf("file permission W/R denied"));
    fd[0] = open(av[1],O_RDONLY);
    fd[1] = open(av[4],O_WRONLY | O_TRUNC | O_CREAT , 0644);
    if (fd[0] < 0 || fd[1] < 0)
        return (printf("Error opening W/R files"));
    pipex(fd,av[2],av[3],env);
    return (EXIT_SUCCESS);
}

// int main (int ac ,char**av, char ** env)
// {
// 	char ** pars = parsing(env);   
// 	// while (1)
// 	//     sleep(1);
// }






/*

	****left to do :

	norminette
	checksssss comment correction
	make sure all tests pass
	makefile works properly
	leaks

*/