/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchouikh <zchouikh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:32:24 by zchouikh          #+#    #+#             */
/*   Updated: 2025/10/24 09:55:59 by zchouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	w;

	w = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		w++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (w);
}

static char	*ft_dupword(char *start, char *end)
{
	int		len;
	int		i;
	char	*dup;

	len = end - start;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = *start++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**ft_failed(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**res;
	char	*start;

	if (!s)
		return (NULL);
	words = ft_countword(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		res[i++] = ft_dupword(start, (char *)s);
		if (!res[i - 1])
			return (ft_failed(res, i - 2));
	}
	res[i] = NULL;
	return ((char **)res);
}
