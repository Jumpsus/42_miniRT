/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:01:24 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/22 10:37:39 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_str(char c, char *str)
{
	if (str && *str)
	{
		while (*str)
			if (c == *str++)
				return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (s1[++i])
		if (!is_in_str(s1[i], (char *)set))
			break ;
	if (!s1[i])
		return (ft_strdup(""));
	j = i + ft_strlen(s1 + i);
	while (s1[--j])
		if (!is_in_str(s1[j], (char *)set))
			break ;
	newstr = malloc((j - i + 2) * sizeof(*newstr));
	k = 0;
	while (i <= j)
		newstr[k++] = s1[i++];
	newstr[k] = 0;
	return (newstr);
}
