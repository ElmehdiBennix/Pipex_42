/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:05:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/09 23:52:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *parsing(char **env);
int     child_proc(int fd1 , char* cmd1 , char** path);
int     parent_proc(int fd2 , char* cmd2 , char** path);
void    pipex(int fd1, char* cmd1, char* cmd2, int fd2 , char **env);

#endif