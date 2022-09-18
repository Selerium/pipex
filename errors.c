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
void	ft_printexit(int n, char **string)
{
	if (n == 1)
		ft_printf("Incorrect number of arguments. Exiting.\n");
	else if (n == 2)
	{
		perror("Command not found");
		ft_specialfree(string);
		exit(127);
	}
	else if (n == 3)
	{
		perror("Error in creating child. Exiting");
		exit(3);
	}
	else if (n == 4)
		perror("File not found");
	else if (n == 5)
	{
		perror("No permission to use command");
		exit(126);
	}
	else if (n == 6)
		perror("Error in creating pipe");
	else if (n == 7)
		perror("PATH variable doesn't exist. Exiting");
	exit(1);
}

void	ft_printerror(void)
{
	perror("Error in allocating memory");
	exit(7);
}
