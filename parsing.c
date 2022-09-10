/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/10 15:48:33 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

/**
 * @brief uses a forked process to run a sh command "where", returning the file
 * 			path of a command cmd given in
 * @param cmd command to search for
 * @param env environment variable
 * @param fd pipe for getting output of execve
 * @return char* which is the final path variable
 */
char	*ft_findcmd(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];
	char	*args[3];
	char	*path;

	path = (char *) ft_calloc (30, sizeof(char));
	args[0] = "/usr/bin/which";
	args[1] = cmd;
	args[2] = NULL;
	pipe(fd);
	pid = ft_fork();
	if (pid == 0)
	{
		close(fd[READ]);
		dup2(fd[WRITE], STDOUT_FILENO);
		execve(args[0], args, env);
	}
	close(fd[WRITE]);
	wait(NULL);
	read(fd[READ], path, 30);
	path[ft_strlen(path) - 1] = '\0';
	return (path);
}


void	ft_first(char *infile, int fd[2])
{
	int	f;

	if (access(infile, F_OK) != 0)
		ft_printexit(4, infile);
	f = open(infile, O_RDONLY);
	dup2(f, STDIN_FILENO);
	close(f);
	close(fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
}

void	ft_last(int fd[2], char *filename)
{
	int	file;

	dup2(fd[READ], STDIN_FILENO);
	close(fd[READ]);
	unlink(filename);
	file = open(filename, O_CREAT | O_WRONLY, 0777);
	dup2(file, STDOUT_FILENO);
	close(file);
	close(fd[WRITE]);
}

void	ft_checkcmd(char *cmdpath, char *cmd)
{
	if (access(cmdpath, F_OK) != 0)
		ft_printexit(2, cmd);
	if (access(cmdpath, X_OK) != 0)
		ft_printexit(5, cmd);
}