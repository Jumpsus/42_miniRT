/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:09:48 by prrattan          #+#    #+#             */
/*   Updated: 2022/02/22 11:37:10 by prrattan         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	nbr;
	char	temp[12];

	i = 0;
	nbr = n;
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
	ft_putstr_fd(ft_strrev(temp, i), fd);
}
