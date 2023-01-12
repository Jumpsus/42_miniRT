/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:00:16 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 13:00:17 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	scene_set_plane(t_object *obj, char *s)
{
	char	**inp;

	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (scene_assign_position(obj, inp[0]))
			if (scene_assign_normalized(obj, inp[1]))
				if (scene_assign_color(obj, inp[2]))
					obj->id = PLANE;
	}
	else
		ft_putendl_fd("Error\nPlane must only \
consist of xyz coordinates, 3d normalized orientation \
vector and rgb colors", STDERR_FILENO);
	free_2d(inp);
	return (obj->id);
}

int	scene_set_cylinder(t_object *obj, char *s)
{
	char	**inp;

	inp = ft_split(s, ' ');
	if (size_2d(inp) == 5)
	{
		if (scene_assign_position(obj, inp[0]))
			if (scene_assign_normalized(obj, inp[1]))
				if (scene_assign_diam_height(obj, inp[2], 'd'))
					if (scene_assign_diam_height(obj, inp[3], 'h'))
						if (scene_assign_color(obj, inp[4]))
							obj->id = CYLINDER;
	}
	else
		ft_putendl_fd("Error\nCylinder must only \
consist of xyz coordinates, 3d normalized orientation \
vector, diameter, height and rgb colors", STDERR_FILENO);
	free_2d(inp);
	return (obj->id);
}
