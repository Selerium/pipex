/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:12:56 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/07 01:52:25 by jadithya         ###   ########.fr       */
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
	if (argc < 5)
		ft_printexit();
	ft_parse(argv[1], argv[2], env);
	return (0);
}
