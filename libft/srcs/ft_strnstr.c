/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:44:50 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/21 19:15:22 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		len_n;
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	len_n = (int)(n - len_s2 + 1);
	if ((int)n < 0)
		len_n = (int)(ft_strlen(s1));
	if (!*s2)
		return ((char *)s1);
	while (*s1 && len_n > 0)
	{
		if (ft_strncmp(s1, s2, len_s2) == 0)
			return ((char *)s1);
		s1++;
		len_n--;
	}
	return (0);
}
