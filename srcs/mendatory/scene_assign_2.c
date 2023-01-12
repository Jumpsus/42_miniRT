/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_assign_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:59:32 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 12:59:33 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	check_input(char *s, double start, double end)
{
	double	n;
	int		dot;
	int		len;

	dot = 0;
	len = -1;
	if (*s == '+' || *s == '-')
		len++;
	while (s[++len])
	{
		if (!dot && s[len] == '.')
			dot = 1;
		else if (!ft_isdigit(s[len]))
			return (0);
	}
	n = ft_atof(s);
	return (n >= start && n <= end);
}

int	scene_assign_ratio(t_object *obj, char *s)
{
	char	*err;

	err = "Error\nRatio must be of the format \
\"n\" where n is a double in the range [0,1]";
	if (check_input(s, 0, 1))
	{
		obj->ratio = ft_atof(s);
		return (1);
	}
	ft_putendl_fd(err, STDERR_FILENO);
	return (0);
}

int	scene_assign_view(t_object *obj, char *s)
{
	char	*err;

	err = "Error\nField of view must be of the format \
\"n\" where n is a double in the range [0,180]";
	if (check_input(s, 0, 180))
	{
		obj->fov = ft_atof(s);
		return (1);
	}
	ft_putendl_fd(err, STDERR_FILENO);
	return (0);
}

int	scene_assign_diam_height(t_object *obj, char *s, char type)
{
	char	*err;

	if (!(type == 'h' || type == 'd'))
		return (0);
	else if (type == 'h')
		err = "Error\nHeight must be of the format \
\"n\" where n is a double";
	else if (type == 'd')
		err = "Error\nDiameter must be of the format \
\"n\" where n is a double";
	if (check_input(s, -DBL_MAX, DBL_MAX))
	{
		if (type == 'h')
			obj->height = ft_atof(s);
		else if (type == 'd')
			obj->radius = ft_atof(s) * 0.5;
		return (1);
	}
	ft_putendl_fd(err, STDERR_FILENO);
	return (0);
}
