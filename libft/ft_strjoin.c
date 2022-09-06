/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:39:20 by jadithya          #+#    #+#             */
/*   Updated: 2022/06/26 20:45:31 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	j = (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (j == 0)
		return (NULL);
	newstr = (char *) malloc (j * sizeof(char));
	if (!newstr)
		return (NULL);
	i = -1;
	while (++i < ft_strlen((char *) s1))
		newstr[i] = s1[i];
	j = 0;
	while (j < ft_strlen((char *) s2))
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
