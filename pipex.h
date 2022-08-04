/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:21:12 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/05 03:31:36 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<sys/wait.h>
# include<fcntl.h>
# include"printf/libftprintf.h"

void	ft_printexit(void);
void	ft_execute(char *file, char *cmd, char **env);

#endif