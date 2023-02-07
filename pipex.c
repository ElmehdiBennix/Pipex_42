/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:17:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/02/07 01:47:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    pipex(int fd1, char* cmd1, char* cmd2, int fd2) // for child processes / char *cmd1, outs put it to parent as input pipe to char *cmd2, to finish 
{
    // for process to child and parrent split the tasks so that the input for the child finishes as input for the parent to finish to simulate a pipe 
    //note / wait for child to finish the exec
}
int main (int ac , char **av , char **env) // 0 for a.out next for next in exec
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
        perror("Error opening W/R files");
        return 1;
    }
    // execve();
    // pipex(fd[0],,,fd[1]);
    return 0;
}