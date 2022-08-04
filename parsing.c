/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:52:22 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/04 22:57:09 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

//char	*ft_findcmd(char *cmd, char **env)
//{
//	int	i;

//	i = 0;
//	while (env[i][0])
//	{
//		if (ft_substr(env[i], 0, 4) == "PATH")
//			break;
//	}

//}

void	ft_execute(char *infile, char *cmd, char **env)
{
	char	**split;
	pid_t	pid;
	int		status;
	char	*cmdpath;

	split = ft_split(cmd, ' ');
	//cmdpath = ft_findcmd(split[0], env);
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/ls", split, env);
		exit(0);
	}
	else if (pid != -1)
		wait(&status);
	ft_printf("\ntesting values: pid - %d, status - %d", pid, status);
}
