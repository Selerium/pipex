/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/18 14:54:57 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_first(char *infile, int fd[2], char **cmd, char *cmdpath)
{
	int	f;

	if (access(infile, F_OK | R_OK) != 0)
	{
		close(fd[READ]);
		close(fd[WRITE]);
		ft_free(cmd, cmdpath);
		ft_printexit(4, &infile);
	}
	f = open(infile, O_RDONLY);
	if (f == -1)
	{
		close(fd[READ]);
		close(fd[WRITE]);
		ft_printf("Infile couldn't be opened. Exiting.\n");
		ft_free(cmd, cmdpath);
		exit(1);
	}
	dup2(f, STDIN_FILENO);
	close(f);
	close(fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
}

void	ft_last(int fd[2], char *filename, char **cmd, char *cmdpath)
{
	int	file;

	dup2(fd[READ], STDIN_FILENO);
	close(fd[READ]);
	if (access(filename, W_OK) != 0)
	{
		close(fd[WRITE]);
		ft_printf("Outfile couldn't be opened. Exiting.\n");
		ft_free(cmd, cmdpath);
		exit(1);
	}
	unlink(filename);
	file = open(filename, O_CREAT | O_WRONLY, 0777);
	if (file == -1)
	{
		close(fd[WRITE]);
		ft_printf("Outfile couldn't be opened. Exiting.\n");
		ft_free(cmd, cmdpath);
		exit(1);
	}
	dup2(file, STDOUT_FILENO);
	close(file);
	close(fd[WRITE]);
}

void	ft_checkcmd(char *cmdpath, char **cmd, int fd[2])
{
	if (!cmdpath || access(cmdpath, F_OK) != 0)
	{
		close(fd[WRITE]);
		close(fd[READ]);
		if (cmdpath)
			free(cmdpath);
		ft_printexit(2, cmd);
	}
	if (access(cmdpath, X_OK) != 0)
	{
		close(fd[WRITE]);
		close(fd[READ]);
		free(cmdpath);
		ft_specialfree(cmd);
		ft_printexit(5, NULL);
	}
}
