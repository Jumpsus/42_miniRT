/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:36:01 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 10:36:02 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

static t_color	diffuse_reflection(t_hit hit, t_object *l_obj, t_point l_dir)
{
	t_color	light;
	double	nl;

	nl = vector_dot(hit.hit_norm, l_dir);
	if (nl < 0)
		nl = 0;
	light = color_multiply_n(l_obj->color, l_obj->ratio * nl);
	return (light);
}

static t_color	specular_reflection(t_hit hit, t_object camera,
	t_object *l_obj, t_point l_dir)
{
	t_ray	v_ray;
	t_point	h_dir;
	t_color	light;
	double	nh;

	v_ray = create_ray(hit.hit_pos, vector_subtract(camera.pos, hit.hit_pos));
	h_dir = unit_vector(vector_add(v_ray.dir, l_dir));
	nh = vector_dot(hit.hit_norm, h_dir);
	if (nh < 0)
		nh = 0;
	light = color_multiply_n(l_obj->color, l_obj->ratio * pow(nh, SHININESS));
	return (light);
}

/*
until page-17 https://www.cs.cornell.edu/courses/
cs4620/2014fa/lectures/05rt-shading.pdf
*/
static t_color	get_shaded_color(t_main *data, t_hit hit)
{
	t_object	*l_obj;
	t_point		l_dir;
	t_ray		l_ray;
	t_color		light;

	light = color_multiply_n(data->ambient.color, data->ambient.ratio);
	l_obj = data->light;
	while (l_obj)
	{
		l_dir = unit_vector(vector_subtract(l_obj->pos, hit.hit_pos));
		l_ray = create_ray(hit.hit_pos, l_dir);
		l_ray = create_ray(ray_at(l_ray, 1e-5), l_dir);
		if (!hit_object(data, l_ray).is_hit)
		{
			light = color_add(light, diffuse_reflection(hit, l_obj, l_dir));
			light = color_add(light, specular_reflection(hit, data->camera,
						l_obj, l_dir));
		}
		l_obj = l_obj->next;
	}
	return (color_normalize(color_multiply_color(hit.hit_obj->color, light)));
}

t_color	trace(t_main *data, t_ray r)
{
	t_hit	hit;

	hit = hit_object(data, r);
	if (hit.is_hit)
		return (get_shaded_color(data, hit));
	return (data->background);
}
