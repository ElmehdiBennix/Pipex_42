/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:16:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/20 03:03:42 by ebennix          ###   ########.fr       */
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
	if (path == NULL)
		return (NULL);
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
	err = -1 ;
	cmds = ft_split(cmd1, ' ');
	dup2(fd, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	close(fd);
	if (fd < 0)
	{
		free_2d(cmds);
		exit(1);
	}
	else if (access(cmd1, X_OK) == 0)
		execve(cmd1, cmds, NULL);
	else if (*cmd1 == '/')
		ft_printf("no such file or directory: %s\n", cmd1);
	else
	{
		while (path[i] && err == -1)
		{
			fullpath = ft_strjoin(path[i], cmds[0]);
			err = execve(fullpath, cmds, NULL);
			free(fullpath);
			i++;
		}
		if (err == -1)
		{
			ft_printf("command not found: %s\n", cmds[0]);
			free_2d(cmds);
			exit(EXIT_FAILURE);
		}
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
	err = -1 ;
	cmds = ft_split(cmd2, ' ');
	dup2(fd, STDOUT_FILENO);
	dup2(pip[0], STDIN_FILENO);
	close(pip[1]);
	close(fd);
	if (access(cmd2, X_OK) == 0)
		execve(cmd2, cmds, NULL);
	else if (*cmd2 == '/')
		ft_printf("no such file or directory: %s\n", cmd2);
	else
	{
		while (path[i] && err == -1)
		{
			fullpath = ft_strjoin(path[i], cmds[0]);
			err = execve(fullpath, cmds, NULL);
			free(fullpath);
			i++;
		}
		if (err == -1)
		{
			ft_printf("command not found: %s\n", cmds[0]);
			free_2d(cmds);
			exit(EXIT_FAILURE);
		}
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
		free_2d(path);
		exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	int		err[3];
	int		fd[2];
	char	**path;

	if (ac != 5)
		return (ft_printf("error 4 arguments are required"));
	err[0] = access(av[1], R_OK);
	err[1] = access(av[1], F_OK);
	err[2] = access(av[4], W_OK | R_OK);
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (err[1] == -1)
		ft_printf("no such file or directory : %s\n", av[1]);
	else if (err[0] == -1)
		ft_printf("permission denied : %s\n", av[1]);
	if (err[2] == -1)
		return (ft_printf("permission denied : %s\n", av[4]));
	path = parsing(env);
	if (path == NULL)
		return (ft_printf("environnement not found:"));
	pipex(fd, av[2], av[3], path);
}
