/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:05:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/14 20:02:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "Printf/ft_printf.h"

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**free_2d(char **str);
char	**ft_split(char *s, char c);

char	**parsing(char **env);
void	child_proc(int fd, char *cmd1, char **path, int *pip);
void	parent_proc(int fd, char *cmd2, char **path, int *pip);
void	pipex(int *fd, char *cmd1, char *cmd2, char **path);

#endif