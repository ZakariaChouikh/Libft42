/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchouikh <zchouikh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:18:05 by zchouikh          #+#    #+#             */
/*   Updated: 2025/10/24 10:00:55 by zchouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, int c)
{
	while (*set)
	{
		if (*set == (unsigned char)c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_isset(set, s1[i]))
		i++;
	while (i < len && ft_isset(set, s1[len - 1]))
		len--;
	str = ft_substr(s1, i, len - i);
	if (!str)
		return (NULL);
	return (str);
}
