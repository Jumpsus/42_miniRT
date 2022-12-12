/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:04:05 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/22 16:31:06 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*p;

	p = (unsigned char *)s;
	len = n;
	while (len > 0)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
		len--;
	}
	return (0);
}
