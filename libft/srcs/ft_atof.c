/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:12:51 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 13:11:48 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_int(const char *nptr)
{
	int			i;
	long double	result;

	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			break ;
		result = (nptr[i++] - '0') + result * 10;
	}
	return (result);
}

static double	ft_atof_float(const char *nptr)
{
	int			i;
	int			e;
	long double	result;

	i = 0;
	e = 0;
	result = 0;
	if (nptr[i] == '.')
	{
		while (nptr[++i])
		{
			if (!ft_isdigit(nptr[i]))
				break ;
			result = (nptr[i] - '0') + result * 10;
			e--;
		}
	}
	while (e++ < 0)
		result *= 0.1;
	return (result);
}

double	ft_atof(const char *nptr)
{
	int			i;
	int			sign;
	long double	result;

	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	result = ft_atof_int(nptr);
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			break ;
		i++;
	}
	result += ft_atof_float(nptr + i);
	return (result * sign);
}
