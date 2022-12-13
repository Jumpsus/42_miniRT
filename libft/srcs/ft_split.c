/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:38:03 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/21 21:19:55 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_untilc(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strdup_untilc(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen_untilc(s, c) + 1) * sizeof(*str));
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	ft_piece(char *s, char c)
{
	int	piece;

	piece = 0;
	if (*s != c)
		piece++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			piece++;
		s++;
	}
	return (piece);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*cpy;
	char	**arr;

	i = 0;
	cpy = ft_strdup(s);
	arr = malloc((ft_piece(cpy, c) + 1) * sizeof(*arr));
	if (*cpy != c && *cpy)
		arr[i++] = ft_strdup_untilc(cpy, c);
	while (*cpy)
	{
		if (*cpy == c && *(cpy + 1) != c && *(cpy + 1))
			arr[i++] = ft_strdup_untilc(cpy + 1, c);
		cpy++;
	}
	arr[i] = 0;
	free(cpy - ft_strlen(s));
	return (arr);
}
