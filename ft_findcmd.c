/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:18:09 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/17 16:18:09 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	*ft_findpath(char *paths, char *cmd)
{
	int		i;
	int		j;
	char	*path;

	i = 5;
	while (paths[i])
	{
		j = 0;
		while (paths[i + j] && paths[i + j] != ':')
			j++;
		path = ft_substr(paths, i, j);
		if (path[ft_strlen(path) - 1] != '/')
			path = ft_wrapjoin(path, "/");
		path = ft_wrapjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		if (paths[i + j] == '\0')
			break ;
		i += (j + 1);
	}
	return (NULL);
}

char	*ft_findcmd(char *cmd, char **env)
{
	int		i;
	int		flag;
	char	*path;

	i = 0;
	flag = 0;
	while (env[i] && !flag)
	{
		if (ft_strnstr(env[i], "PATH", 4) != NULL)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
		ft_printexit(7, NULL);
	path = ft_findpath(env[i], cmd);
	return (path);
}

// int	main(int argc, char **argv, char **env)
// {
// 	if (argc && argv) {}
// 	ft_printf("%s\n", ft_findcmd("ls", env));
// 	return (0);
// }