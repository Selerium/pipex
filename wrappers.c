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

char	*ft_wrapjoin(char *str1, char *str2)
{
	char	*temp;

	temp = str1;
	str1 = ft_strjoin(str1, str2);
	free(temp);
	return (str1);
}

void	ft_specialfree(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

void	ft_free(char **cmd, char *cmdpath)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	free(cmdpath);
}

/**
 * @brief a wrapper for the "fork()" function to check for errors in child
 * 			creation
 * @return pid_t pid value (0 for child, >0 for parent)
 */
pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_printexit(3, NULL);
	return (pid);
}

int	ft_pipe(int fd[2])
{
	int	x;

	x = pipe(fd);
	if (x == -1)
		ft_printexit(6, NULL);
	return (x);
}
