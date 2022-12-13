/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:55:52 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/22 16:32:35 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cp_dest;
	char	*cp_src;
	char	temp[1000];

	cp_dest = dest;
	cp_src = (char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = cp_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		cp_dest[i] = temp[i];
		i++;
	}
	return (dest);
}
