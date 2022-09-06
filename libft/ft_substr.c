/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:21:15 by jadithya          #+#    #+#             */
/*   Updated: 2022/06/26 21:07:01 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	if (start > (ft_strlen((char *) s) - 1))
		return (ft_strdup(""));
	if (len > ft_strlen((char *) s))
		len = ft_strlen((char *) s);
	newstr = (char *) malloc ((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	if (len != 0)
	{
		while (i < len && i < ft_strlen((char *) s))
		{
			newstr[i] = (char) s[(size_t) start + i];
			i++;
		}
	}
	newstr[i] = '\0';
	return (newstr);
}
