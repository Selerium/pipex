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
		ft_printf("Incorrect number of arguments. Exiting.\n"); //1
	else if (n == 2)
		ft_printf("Command %s not found. Exiting.\n", string); //127
	else if (n == 3)
		ft_printf("Error in creating child. Exiting.\n"); //3
	else if (n == 4)
		ft_printf("File named \"%s\" not found. Exiting.\n"); //1
	exit(1);
}

void	ft_printerror(void)
{
	ft_printf("Error in allocating memory. Exiting.\n");
	exit(-1);
}