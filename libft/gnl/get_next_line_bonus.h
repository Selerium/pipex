/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:48:08 by jadithya          #+#    #+#             */
/*   Updated: 2022/07/14 23:24:37 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include<stdlib.h>
# include<limits.h>
# include<stdio.h>
# include<unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_splithold(char *hold);
int		ft_hasnextline(char *check);
char	*ft_join(char *s1, char *s2);
void	*ft_calloc(size_t num, size_t size);

#endif