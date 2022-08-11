/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:12:56 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/11 19:12:41 by jadithya         ###   ########.fr       */
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
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (argc != 5)
		ft_printexit();
	pipe(fd);
	pid1 = ft_fork();
	pid2 = 25;
	// if (pid1 != 0)
	// 	pid2 = ft_fork();
	if (pid1 && pid2 && waitpid(pid1, NULL, 0) && waitpid(pid2, NULL, 0))
		ft_printf("%d, %d\n", pid1, pid2);
	if (!pid1)
		ft_parse(argv[1], argv[2], env, 0, fd);
	waitpid(pid1, NULL, 0);
	// if (!pid2)
	// 	ft_printf("child 2 reporting\n");
	return (0);
}
