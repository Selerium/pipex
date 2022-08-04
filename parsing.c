/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/05 03:51:17 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

// char	*ft_findcmd(char *cmd, char **env)
// {
// 	int		i;
// 	char	**paths;

// 	i = 0;
// 	while (env[i][0])
// 	{
// 		if (ft_substr(env[i], 0, 4) == "PATH")
// 			break;
// 		i++;
// 	}
// 	if (env[i] == NULL)
// 	{
// 		ft_printf("Command not found. Exiting.");
// 		exit(0);
// 	}
// 	paths = ft_split(env[i][5], ':');
// 	while (paths[i])
// 	{
// 		i++;
// 	}
// }

char	*ft_findcmd(char *cmd, char **env)
{
	pid_t	pid;
	int		status;
	char	*args[2];
	int		fd;

	args[0] = "/usr/bin/which";
	args[1] = cmd;
	args[2] = NULL;
	pid = fork();
	if (pid == 0)
		execve(args[0], args, env); //pass into pipe to be returned
	else if (pid == -1)
	{
		ft_printf("Error in creating child. Exiting.\n");
		exit(0);
	}
	wait(&status);
	fd = open("command.txt", O_RDONLY);
	// use getnextline to get command
	// return the command to ft_execute
	close(fd);
	cmd = "/usr/bin/ls"; // receiving end of pipe
	return (cmd);
}

void	ft_execute(char *file, char *cmd, char **env)
{
	char	**split;
	pid_t	pid;
	int		status;
	char	*cmdpath;

	split = ft_split(cmd, ' ');
	file = "hi";
	ft_printf("test\n%s\n", file);
	cmdpath = ft_findcmd(split[0], env);
	pid = fork();
	if (pid == 0)
		execve(cmdpath, split, env); //to be piped to next function
	else if (pid == -1)
	{
		ft_printf("Error in creating child. Exiting.\n");
		exit(0);
	}
	wait(&status);
	// ft_printf("waiting pid = %d\n", pid);
	// ft_printf("testing values: pid - %d, status - %d\n", pid, status);
}
