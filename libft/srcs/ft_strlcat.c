/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:09:07 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/19 22:09:35 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	i = len_dst;
	j = 0;
	while (src[j])
	{
		if (j < size - len_dst - 1 && size > len_dst)
			dst[i++] = src[j];
		j++;
	}
	if (size < len_dst)
		return (j + size);
	else if (size > len_dst)
		dst[i] = 0;
	return (len_dst + j);
}
