/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/10 19:27:47 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

/**
 * @brief a wrapper for the "fork()" function to check for errors in child
 * 			creation
 * @return pid_t which is the pid value of the process (0 for child, >0 for parent)
 */
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
	path[ft_strlen(path) - 1] = '\0';
	return (path);
}

/**
 * @brief wrapper for "execve()"
 * 
 * @param path provides the path to the command
 * @param args command and its arguments
 * @param env enviornment variables
 */
void	ft_execute(char *path, char **args, char **env)
{
	pid_t	pid;
	int		status;

	pid = ft_fork();
	if (pid == 0)
		execve(path, args, env);
	wait (&status);
}

/**
 * @brief parses through the arguments to get command and its file path, then
 * 			calls "execve()" to run the said command with provided args
 * 
 * @param infile name of infile
 * @param args arguments for the cmd
 * @param env environment variable
 */
void	ft_parse(char *file, char *args, char **env, int flag)
{
	char		*cmdpath;
	static int	fd[2];
	int			stdoutcpy;
	char		**cmd;

	cmd = ft_split(args, ' ');
	if (!fd[0])
		pipe(fd);
	stdoutcpy = dup(STDOUT_FILENO);
	dup2(fd[WRITE], STDOUT_FILENO);
	cmdpath = ft_findcmd(cmd[0], env, fd);
	if (flag == 0)
	{
		dup2(open(file, O_RDONLY), STDIN_FILENO);
		ft_execute(cmdpath, cmd, env);
	}
	//else if (flag == 2)
	//{
	//	dup2(open("temp.txt", O_RDONLY), STDIN_FILENO);
	//	dup2(temp, STDOUT_FILENO);
	//}
	close(fd[READ]);
	close(fd[WRITE]);
	free(cmdpath);
}
