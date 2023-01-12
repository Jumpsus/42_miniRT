/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:00:37 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 13:00:38 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

void	scene_set_defalt(t_object *obj)
{
	obj->id = 0;
	obj->pos = (t_point){0, 0, 0};
	obj->color = (t_color){0, 0, 0};
	obj->norm = (t_point){0, 0, 0};
	obj->ratio = 0;
	obj->fov = 0;
	obj->radius = 0;
	obj->height = 0;
	obj->next = 0;
}

int	scene_set_ambient(t_object *obj, char *s)
{
	char	**inp;

	if (obj->id == AMBIENT)
	{
		ft_putendl_fd("Error\nAmbient lighting can \
only be declared once in the scene", STDERR_FILENO);
		return (0);
	}
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 2)
	{
		if (scene_assign_ratio(obj, inp[0]))
			if (scene_assign_color(obj, inp[1]))
				obj->id = AMBIENT;
	}
	else
		ft_putendl_fd("Error\nAmbient lighting \
must only consist of ambient lighting ratio \
and rgb colors", STDERR_FILENO);
	free_2d(inp);
	return (obj->id);
}

int	scene_set_camera(t_object *obj, char *s)
{
	char	**inp;

	if (obj->id == CAMERA)
	{
		ft_putendl_fd("Error\nCamera can only be \
declared once in the scene", STDERR_FILENO);
		return (0);
	}
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (scene_assign_position(obj, inp[0]))
			if (scene_assign_normalized(obj, inp[1]))
				if (scene_assign_view(obj, inp[2]))
					obj->id = CAMERA;
	}
	else
		ft_putendl_fd("Error\nCamera must only \
consist of xyz coordinates, 3d normalized orientation \
vector and horizontal field of view", STDERR_FILENO);
	free_2d(inp);
	return (obj->id);
}

int	scene_set_light(t_object *obj, char *s)
{
	char	**inp;

	if (obj->id == LIGHT)
	{
		ft_putendl_fd("Error\nLight can only be \
declared once in the scene", STDERR_FILENO);
		return (0);
	}
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (scene_assign_position(obj, inp[0]))
			if (scene_assign_ratio(obj, inp[1]))
				if (scene_assign_color(obj, inp[2]))
					obj->id = LIGHT;
	}
	else
		ft_putendl_fd("Error\nLight must only \
consist of xyz coordinates, brightness ratio and \
rgb colors", STDERR_FILENO);
	free_2d(inp);
	return (obj->id);
}

int	scene_set_sphere(t_object *obj, char *s)
{
	char	**inp;

	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (scene_assign_position(obj, inp[0]))
			if (scene_assign_diam_height(obj, inp[1], 'd'))
				if (scene_assign_color(obj, inp[2]))
					obj->id = SPHERE;
	}
	else
		ft_putendl_fd("Error\nSphere must only \
consist of xyz coordinates, diameter and rgb \
colors", STDERR_FILENO);
	free_2d(inp);
	return (obj->id);
}
