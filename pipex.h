/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bennix <bennix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:05:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/11 15:18:38 by bennix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char    **parsing(char **env);
int child_proc(int fd ,char* cmd1 , char** path , int *pip);
int parent_proc(int fd , char* cmd2 , char** path , int *pip);
void    pipex(int fd[2], char* cmd1, char* cmd2, char **env);

#endif