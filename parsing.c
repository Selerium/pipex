/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/20 20:17:09 by jadithya         ###   ########.fr       */
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
		exit(1);
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

/**
 * @brief wrapper for "execve()"
 * 
 * @param path provides the path to the command
 * @param args command and its arguments
 * @param env enviornment variables
 */
// void	ft_execute(char *path, char **args, char **env)
// {
// 	pid_t	pid;
// 	int		status;

// 	pid = ft_fork();
// 	if (pid == 0)
// 		execve(path, args, env);
// 	wait (&status);
// }

void	ft_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	ft_outfile(int fd[2])
{
	close(fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
}

void	ft_finalin(int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	ft_finalout(char *filename, int fd)
{
	int	file;

	unlink(filename);
	file = open(filename, O_CREAT | O_WRONLY, 0777);
	dup2(file, STDOUT_FILENO);
	close(file);
	close(fd);
}


/**
 * @brief parses through the arguments to get command and its file path, then
 * 			calls "execve()" to run the said command with provided args
 * 
 * @param infile name of infile
 * @param args arguments for the cmd
 * @param env environment variable
 */
// void	ft_parse(char *file, char *args, char **env, int fd[2])
// {
// 	char	*cmdpath;
// 	char	**cmd;

// 	cmd = ft_split(args, ' ');
// 	dup2(fd[WRITE], STDOUT_FILENO);
// 	return(ft_findcmd(cmd[0], env));
// }
