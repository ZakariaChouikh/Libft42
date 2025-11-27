/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchouikh <zchouikh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:56:13 by zchouikh          #+#    #+#             */
/*   Updated: 2025/11/01 19:00:08 by zchouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char) c)
			last = s;
		s++;
	}
	if (last != NULL)
		return ((char *)last);
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
