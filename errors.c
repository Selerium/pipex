/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:30:06 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/06 15:30:06 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

/**
 * @brief takes in an error number and displays respective error message
 * 
 * @param n error number
 */
void	ft_printexit(int n, char *string)
{
	if (n == 1)
		ft_printf("Incorrect number of arguments. Exiting.\n");
	else if (n == 2)
	{
		ft_printf("Command %s not found. Exiting.\n", string);
		exit(127);
	}
	else if (n == 3)
	{
		ft_printf("Error in creating child. Exiting.\n");
		exit(3);
	}
	else if (n == 4)
		ft_printf("File named \"%s\" not found. Exiting.\n");
	else if (n == 5)
	{
		ft_printf("You don't have permission to use this command.\n", string);
		exit(126);
	}
	else if (n == 6)
		ft_printf("Error in creating pipe. Exiting.\n");
	exit(1);
}

void	ft_printerror(void)
{
	ft_printf("Error in allocating memory. Exiting.\n");
	exit(-1);
}