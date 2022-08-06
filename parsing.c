/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/07 01:33:24 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_printf("Error in creating child. Exiting.\n");
		exit(-1);
	}
	else
		return (pid);
}

/**
 * @brief uses a forked process to run a sh command "where", returning the file
 * 			path of a command cmd given in
 * @param cmd command to search for
 * @param env environment variable
 * @param fd pipe for getting output of execve
 * @return char* which is the final path variable
 */
static char	*ft_findcmd(char *cmd, char **env, int fd[2])
{
	pid_t	pid;
	int		status;
	char	*args[3];
	char	*path;

	path = (char *) ft_calloc (30, sizeof(char));
	args[0] = "/usr/bin/which";
	args[1] = cmd;
	args[2] = NULL;
	pid = ft_fork();
	if (pid == 0)
		execve(args[0], args, env);
	wait(&status);
	read(fd[READ], path, 30);
	close (fd[READ]);
	path[ft_strlen(path) - 1] = '\0';
	return (path);
}

void	ft_execute(char *path, char **args, char **env)
{
	pid_t	pid;
	int		status;

	pid = ft_fork();
	if (pid == 0)
		execve(path, args, env);
	wait (&status);
}

void	ft_parse(char *file, char *args, char **env)
{
	char	*cmdpath;
	int		fd[2];
	int		stdoutcpy;
	char	**cmd;

	cmd = ft_split(args, ' ');
	pipe(fd);
	stdoutcpy = dup(STDOUT_FILENO);
	dup2(fd[WRITE], STDOUT_FILENO);
	cmdpath = ft_findcmd(cmd[0], env, fd);
	close (fd[WRITE]);
	dup2(stdoutcpy, STDOUT_FILENO);
	ft_execute(cmdpath, cmd, env);
	// ft_printf("%s\n%d\n%s - %s\n\n", cmdpath, ft_strlen(cmdpath), cmd[0], file);
}
