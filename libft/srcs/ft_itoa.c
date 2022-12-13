/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:53:12 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/21 09:20:46 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *tab, int len)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = len - 1;
	while (j > i)
	{
		temp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = temp;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nbr;
	char	*temp;

	i = 0;
	nbr = n;
	temp = malloc(12 * sizeof(*temp));
	if (nbr == 0)
		temp[i++] = '0';
	else if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		temp[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		temp[i++] = '-';
	temp[i] = 0;
	return (ft_strrev(temp, i));
}
