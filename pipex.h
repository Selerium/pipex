/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:21:12 by jadithya          #+#    #+#             */
/*   Updated: 2022/08/20 20:18:00 by jadithya         ###   ########.fr       */
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
void	ft_parse(char *file, char *args, char **env, int fd[2]);
void	ft_execute(char *path, char **args, char **env);
void	ft_infile(char *infile);
void	ft_outfile(int fd[2]);
void	ft_finalout(char *filename, int fd);
void    ft_finalin(int fd);

char	*ft_findcmd(char *cmd, char **env);

pid_t	ft_fork(void);
#endif