/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:48:16 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 10:48:59 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

static void	drop_front_space(char *str)
{
	int	pos;
	int	len;

	pos = -1;
	while (str[++pos])
		if (!ft_isspace(str[pos]))
			break ;
	len = ft_strlen(str + pos);
	ft_memmove(str, str + pos, len);
	str[len] = 0;
}

static void	drop_comma_space(char *str)
{
	int	pos;

	pos = 0;
	while (str[++pos])
	{
		if (str[pos - 1] == ',' && ft_isspace(str[pos]))
			drop_front_space(str + pos--);
		else if (str[pos] == ',' && ft_isspace(str[pos - 1]))
			drop_front_space(str + --pos);
	}
}

void	standardize_columns(char **addr, char *str)
{
	int	pos;

	drop_front_space(str);
	pos = -1;
	while (str[++pos])
		if (ft_isspace(str[pos]))
			break ;
	if (str[pos])
	{
		str[pos] = ' ';
		return (standardize_columns(addr, str + pos + 1));
	}
	drop_comma_space(*addr);
}
