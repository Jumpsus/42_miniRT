/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:54:04 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/13 11:32:28 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	loop_join(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!res)
		return (NULL);
	i = loop_join((char *)s1, res);
	i += loop_join((char *)s2, &res[i]);
	res[i] = '\0';
	return (res);
}
