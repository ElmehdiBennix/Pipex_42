/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:16:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 20:55:45 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing(char **env)
{
	int		i;
	char	*tmp;
	char	**splitz;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i] && path == NULL)
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	splitz = ft_split(path + 5, ':');
	i = 0;
	while (splitz[i])
	{
		tmp = ft_strjoin(splitz[i], "/");
		free(splitz[i]);
		splitz[i] = tmp;
		i++;
	}
	return (splitz);
}

void	child_proc(int fd, char *cmd1, char **path, int *pip)
{
	int		i;
	int		err;
	char	*fullpath;
	char	**cmds;

	i = 0 ;
	cmds = ft_split(cmd1, ' ');
	dup2(fd, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	close(fd);
	while (path[i])
	{
		fullpath = ft_strjoin(path[i], cmds[0]);
		err = execve(fullpath, cmds, NULL);
		free(fullpath);
		i++;
	}
	if (err == -1)
	{
		perror("first command not found");
		exit(EXIT_FAILURE);
	}
	free_2d(cmds);
}

void	parent_proc(int fd, char *cmd2, char **path, int *pip)
{
	int		i;
	int		err;
	char	*fullpath;
	char	**cmds;

	i = 0;
	cmds = ft_split(cmd2, ' ');
	dup2(fd, STDOUT_FILENO);
	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
	close(fd);
	while (path[i])
	{
		fullpath = ft_strjoin(path[i], cmds[0]);
		err = execve(fullpath, cmds, NULL);
		free(fullpath);
		i++;
	}
	if (err == -1)
	{
		perror("second command not found");
		exit(EXIT_FAILURE);
	}
	free_2d(cmds);
}

void	pipex(int *fd, char *cmd1, char *cmd2, char **path)
{
	pid_t	pid;
	int		pip[2];

	if (pipe(pip) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_proc(fd[0], cmd1, path, pip);
	if (pid != 0)
	{
		wait(NULL);
		parent_proc(fd[1], cmd2, path, pip);
	}
	free_2d(path);
}

int	main(int ac, char **av, char **env)
{
	int		err[2];
	int		fd[2];
	char	**path;

	if (ac != 5)
		return (ft_printf("error 4 arguments are required"));
	fd[0] = open(av[1], O_RDONLY | O_CREAT, 0644);
	fd[1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd[0] < 0 || fd[1] < 0)
		return (ft_printf("Error opening W/R files"));
	err[0] = access(av[1], R_OK);
	err[1] = access(av[4], W_OK | R_OK);
	if (err[0] == -1 || err[1] == -1)
		return (ft_printf("file permission W/R denied"));
	path = parsing(env);
	pipex(fd, av[2], av[3], path);
	return (EXIT_SUCCESS);
}
