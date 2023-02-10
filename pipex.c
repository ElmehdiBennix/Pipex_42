// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/06 21:17:28 by ebennix           #+#    #+#             */
// /*   Updated: 2023/02/10 01:17:16 by ebennix          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "pipex.h"

char *parsing(char **env)
{
    int i = 0 ;

	char * path = NULL;
	while (env[i])
	{
		path = ft_strnstr(env[i],"PATH=",5);
		i++;
        if (path != NULL)
            break;
	}
	return (ft_strdup(path)); // gotta free
}

int child_proc(int fd1 , char* cmd1 , char** path)
{
    int i = 0 ;
    char ** cmds = ft_split(cmd1,' ');
    while(path[i])
    {
        //dup2(fd1,stdin);
        char *fullpath = ft_strjoin(path[i],ft_strjoin("/",cmds[0]));
        int err = execve(fullpath,cmds,NULL);
        // if (err == -1)
        // {
        //     printf("cant find the command to execute");
        // }
        i++;
    }
}

int parent_proc(int fd2 , char* cmd2 , char** path)
{
    int i = 0;
    char ** cmds = ft_split(cmd2,' ');
    while(path[i])
    {
        //dup2();
        char *fullpath = ft_strjoin(path[i],ft_strjoin("/",cmds[0]));
        int err = execve(fullpath,cmds,NULL);
        // if (err == -1)
        // {
        //     printf("cant find the command to execute");
        // }
        i++;
    }
}

void    pipex(int fd1, char* cmd1, char* cmd2, int fd2 , char **env)
{
    // for process to child and parrent split the tasks so that the input for the child finishes as input for the parent to finish to simulate a pipe 
    //note -- wait for child to finish the exec
    int err;
    int x;
    char * penv = parsing(env);
    char ** path = ft_split(penv,':');
    pid_t pid = fork();
    if(pid < 0)
        return(perror("fork err"));

    if (pid == 0)
    {
        err = child_proc(fd1,cmd1,path);
        if (err < 0)
            return(perror("error in child"));
    }
    else
    {
        
        wait(NULL);
        // wait for child procc to finish 
        // tqke a look at the acces function 
        err = parent_proc(fd2,cmd2,path);
        if (err < 0)
            return(perror("error in parent"));
    }
}

int main (int ac , char **av , char **env) 
{
    int pid;
    int fd[2];
    if (ac != 5) {
        printf("error passing above 4 args");
        return -1;
    }
    fd[0] = open(av[1],O_RDONLY);
    fd[1] = open(av[4],O_WRONLY | O_TRUNC);
    if (fd[0] < 0 || fd[1] < 0)
    {
        perror("Error opening W/R files");
        return -2;
    }
    pipex(fd[0],av[2],av[3],fd[1],env);
    return 0;
}