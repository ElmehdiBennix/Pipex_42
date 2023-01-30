/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:07:50 by ebennix           #+#    #+#             */
/*   Updated: 2023/01/31 00:57:55 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(int fd1, int fd2) // for child processes / char *cmd1, char *cmd2, 
{
    
}
int main (int ac , char **av) // 0 for a.out next for next in exec
{
    int fd[2];
    if (ac >= 5)
    {
        printf("error passing above 4 args");
        return 1;
    }
    fd[0] = open(av[1],O_RDONLY);
    fd[1] = open(av[4],O_WRONLY);
    if (fd[0] == -1 || fd[1] == -1) {
        perror("Error opening WR files");
        return 1;
    }
    pipex(fd[0],fd[1]);
    return 0;
}