/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:52:27 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/21 21:07:25 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			strlen;
	char			*sub;

	i = 0;
	strlen = ft_strlen(s);
	if (len <= strlen - start)
		sub = malloc((len + 1) * sizeof(*sub));
	else
		sub = malloc((strlen - start + 1) * sizeof(*sub));
	if (!sub)
		return (0);
	while (s[i + start] && i + start < strlen && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
