/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:45 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/22 16:32:08 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cp_dest;
	char	*cp_src;

	cp_dest = dest;
	cp_src = (char *)src;
	i = 0;
	while (i < n)
	{
		cp_dest[i] = cp_src[i];
		i++;
	}
	return (dest);
}
