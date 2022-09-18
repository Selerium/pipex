/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:12:56 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/18 15:03:33 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_wait(int p1, int p2, int fd[2])
{
	int	s2;

	close(fd[READ]);
	close(fd[WRITE]);
	waitpid(p1, NULL, 0);
	waitpid(p2, &s2, 0);
	exit(WEXITSTATUS(s2));
}

void	pipex(int argc, char **argv, char **env, int fd[2])
{
	int		p1;
	int		p2;
	char	**cmd;
	char	*cmdpath;

	ft_pipe(fd);
	p1 = ft_fork();
	if (p1 == 0)
	{
		cmd = ft_split(argv[2], ' ');
		cmdpath = ft_findcmd(cmd[0], env);
		ft_checkcmd(cmdpath, cmd, fd);
		ft_first(argv[1], fd, cmd, cmdpath);
		execve(cmdpath, cmd, env);
	}
	p2 = ft_fork();
	if (p2 == 0)
	{
		cmd = ft_split(argv[argc - 2], ' ');
		cmdpath = ft_findcmd(cmd[0], env);
		ft_checkcmd(cmdpath, cmd, fd);
		ft_last(fd, argv[argc - 1], cmd, cmdpath);
		execve(cmdpath, cmd, env);
	}
	ft_wait(p1, p2, fd);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];

	if (argc != 5)
		ft_printexit(1, NULL);
	if (!argv[2][0] || !argv[3][0])
	{
		ft_printf("Command cannot be an empty string. Exiting.\n");
		exit(8);
	}
	pipex(argc, argv, env, fd);
	return (0);
}
