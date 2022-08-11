/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:21:12 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/10 23:52:57 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ 0
# define WRITE 1

# include<unistd.h>
# include<sys/wait.h>
# include<fcntl.h>
# include"printf/libftprintf.h"

void	ft_printexit(void);
void	ft_printerror(void);
void	ft_parse(char *file, char *args, char **env, int flag, int fd[2]);
pid_t	ft_fork(void);
#endif