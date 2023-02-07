/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:05:38 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/07 01:46:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void    pipex(int fd1, char *cmd1, char *cmd2, int fd2);
char	*ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *str);


#endif