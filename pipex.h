/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:21:12 by jadithya          #+#    #+#             */
/*   Updated: 2022/09/18 12:43:18 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ 0
# define WRITE 1

# include<unistd.h>
# include<sys/wait.h>
# include<fcntl.h>
# include<errno.h>
# include"libft/libft.h"

void	pipex(int argc, char **argv, char **env, int fd[2]);
void	ft_printexit(int n, char **string);
void	ft_printerror(void);
void	ft_parse(char *file, char *args, char **env, int fd[2]);
void	ft_checkcmd(char *cmdpath, char **cmd, int fd[2]);
void	ft_first(char *infile, int fd[2], char **cmd, char *cmdpath);
void	ft_last(int fd[2], char *string, char **cmd, char *cmdpath);
void	ft_execute(char *path, char **args, char **env);
void	ft_wait(int p1, int p2, int fd[2]);
void	ft_free(char **cmd, char *cmdpath);
void	ft_specialfree(char **string);

char	*ft_findcmd(char *cmd, char **env);
char	*ft_wrapjoin(char *str1, char *str2);

pid_t	ft_fork(void);

int		ft_pipe(int fd[2]);

#endif