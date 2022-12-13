/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:04:31 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/21 15:54:03 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	int		i;
	int		k;

	src = (char *)s;
	i = 0;
	k = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			k = i;
		i++;
	}
	if (src[i] == (char)c)
		k = i;
	if ((k > 0) || (k == 0 && src[0] == (char)c))
		return (src + k);
	return (0);
}
