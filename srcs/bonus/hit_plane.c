/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:13 by pratanac          #+#    #+#             */
/*   Updated: 2023/01/12 17:48:15 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

/*
https://www.scratchapixel.com/lessons/3d-basic-rendering/
minimal-ray-tracer-rendering-simple-shapes/
ray-plane-and-ray-disk-intersection
*/
t_hit	hit_plane(t_object *pl, t_ray ray)
{
	double	denom;
	double	t;

	denom = vector_dot(pl->norm, ray.dir);
	if (fabs(denom) > 1e-6)
	{
		t = vector_dot(vector_subtract(pl->pos, ray.orig), pl->norm) / denom;
		return (set_hit_property(t, pl, ray));
	}
	return (set_hit_property(-DBL_MAX, pl, ray));
}
