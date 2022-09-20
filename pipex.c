/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:12:56 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/20 12:28:50 by jadithya         ###   ########.fr       */
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
	if (WIFEXITED(s2))
		exit(WEXITSTATUS(s2));
}

void	pipex(int argc, char **argv, char **env, int fd[2])
{
	int		p[2];
	char	**cmd;
	char	*cmdpath;

	ft_pipe(fd);
	p[0] = ft_fork();
	if (p[0] == 0)
	{
		cmd = ft_split(argv[2], ' ');
		cmdpath = ft_findcmd(cmd[0], env);
		ft_checkcmd(cmdpath, cmd, fd);
		ft_first(argv[1], fd, cmd, cmdpath);
		execve(cmdpath, cmd, env);
	}
	p[argc - 4] = ft_fork();
	if (p[argc - 4] == 0)
	{
		cmd = ft_split(argv[argc - 2], ' ');
		cmdpath = ft_findcmd(cmd[0], env);
		ft_checkcmd(cmdpath, cmd, fd);
		ft_last(fd, argv[argc - 1], cmd, cmdpath);
		execve(cmdpath, cmd, env);
	}
	ft_wait(p[0], p[1], fd);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	i;

	if (argc < 5)
		ft_printexit(1, NULL);
	i = 2;
	while (i < argc)
	{
		if (!argv[i][0])
		{
			ft_printf("Command cannot be an empty string. Exiting.\n");
			exit(8);
		}
		i++;
	}
	pipex(argc, argv, env, fd);
	return (0);
}
