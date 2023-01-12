/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_assign_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:00:02 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 13:00:03 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	check_input(char *s, double start, double end, int is_int)
{
	double	n;
	int		dot;
	int		len;

	dot = 0;
	if (is_int)
		dot = 1;
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

static int	check_all_input(char **inp, double start, double end, int is_int)
{
	int	size;

	size = size_2d(inp);
	while (size-- > 0)
		if (!check_input(inp[size], start, end, is_int))
			return (0);
	return (1);
}

int	scene_assign_position(t_object *obj, char *s)
{
	char	**pos;
	char	*err;

	err = "Error\nx,y,z coordinates must be of \
the format \"n,n,n\" where n is a double";
	pos = ft_split(s, ',');
	if (size_2d(pos) == 3)
	{
		if (check_all_input(pos, -DBL_MAX, DBL_MAX, 0))
		{
			obj->pos.x = ft_atof(pos[0]);
			obj->pos.y = ft_atof(pos[1]);
			obj->pos.z = ft_atof(pos[2]);
			free_2d(pos);
			return (1);
		}
	}
	free_2d(pos);
	ft_putendl_fd(err, STDERR_FILENO);
	return (0);
}

int	scene_assign_color(t_object *obj, char *s)
{
	char	**color;
	char	*err;

	err = "Error\nRGB colors must be of the format \
\"n,n,n\" where n is an integer in the range [0,255]";
	color = ft_split(s, ',');
	if (size_2d(color) == 3)
	{
		if (check_all_input(color, 0, 255, 1))
		{
			obj->color.r = ft_atoi(color[0]);
			obj->color.g = ft_atoi(color[1]);
			obj->color.b = ft_atoi(color[2]);
			obj->color = color_divide(obj->color, 255);
			free_2d(color);
			return (1);
		}
	}
	free_2d(color);
	ft_putendl_fd(err, STDERR_FILENO);
	return (0);
}

int	scene_assign_normalized(t_object *obj, char *s)
{
	char	**norm;
	char	*err;

	err = "Error\n3d normalized orientation vector \
must be of the format \"n,n,n\" where n is \
a double in the range [-1,1]";
	norm = ft_split(s, ',');
	if (size_2d(norm) == 3)
	{
		if (check_all_input(norm, -1, 1, 0))
		{
			obj->norm.x = ft_atof(norm[0]);
			obj->norm.y = ft_atof(norm[1]);
			obj->norm.z = ft_atof(norm[2]);
			obj->norm = unit_vector(obj->norm);
			free_2d(norm);
			return (1);
		}
	}
	free_2d(norm);
	ft_putendl_fd(err, STDERR_FILENO);
	return (0);
}
