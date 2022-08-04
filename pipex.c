/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:12:56 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/04 17:26:26 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printexit(void)
{
	ft_printf("Insufficient number of arguments. Exiting.");
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		ft_printexit();
	return (0);
}
