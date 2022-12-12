/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:56:06 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/22 16:32:54 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			len;
	unsigned char	*p;

	p = s;
	len = n;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (s);
}
