/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:48:10 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/10 15:48:10 by jadithya         ###   ########.fr       */
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
		ft_printexit(3, NULL);
	return (pid);
}

int	ft_pipe(int	fd[2])
{
	int	x;

	x = pipe(fd);
	if (x == -1)
		ft_printexit(6, NULL);
	return (x);
}