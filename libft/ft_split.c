/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:12:55 by jadithya          #+#    #+#             */
/*   Updated: 2022/06/25 21:06:19 by jadithya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

// static int	ft_condition(size_t i, size_t j, const char *s, char c)
// {
// 	if ((s[i] != c || s[j] == '"') && 
// 		s[i] != '\0' && (i - 1 == j || s[i - 1] != '"'))
// 		return (1);
// 	return (0);
// }

static int	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = 0;
	while (i <= ft_strlen((char *) s))
	{
		while (s[i] == c)
			i++;
		j = i++;
		while ((s[i] != c || s[j] == '"')
			&& s[i] != '\0' && (i - 1 == j || s[i - 1] != '"'))
			i++;
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	count;
	char	**newstr;

	i = 0;
	n = -1;
	if (!s)
		return (NULL);
	count = ft_count(s, c);
	newstr = (char **) malloc ((count + 1) * sizeof(char *));
	if (!newstr)
		return (NULL);
	while (++n < count)
	{
		while (s[i] == c || s[i] == '"')
			i++;
		j = i++;
		while ((s[i] != c || s[j - 1] == '"') && s[i] != '\0' && s[i] != '"')
			i++;
		newstr[n] = ft_substr(s, j, i - j);
	}
	newstr[n] = NULL;
	return (newstr);
}
