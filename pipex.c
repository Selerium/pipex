/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:12:56 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/20 20:17:38 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_printexit(void)
{
	ft_printf("Insufficient number of arguments. Exiting.\n");
	exit(-1);
}

void	ft_printerror(void)
{
	ft_printf("Error in allocating memory. Exiting.\n");
	exit(-1);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		p1;
	int		p2;
	char	**cmd;
	char	*cmdpath;

	if (argc != 5)
		ft_printexit();
	pipe(fd);
	p1 = ft_fork();
	if (p1 == 0)
	{
		cmd = ft_split(argv[2], ' ');
		cmdpath = ft_findcmd(cmd[0], env);		
		ft_infile(argv[1]);
		ft_outfile(fd);
		execve(cmdpath, cmd, env);
	}
	p2 = ft_fork();
	if (p2 == 0)
	{
		cmd = ft_split(argv[argc - 2], ' ');
		cmdpath = ft_findcmd(cmd[0], env);		
		ft_finalin(fd[READ]);
		ft_finalout(argv[argc - 1], fd[WRITE]);
		execve(cmdpath, cmd, env);
	}
	close(fd[READ]);
	close(fd[WRITE]);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
	return (0);
}
