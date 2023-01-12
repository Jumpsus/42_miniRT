/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:37:24 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 13:09:16 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_hit	get_hit(t_object *cur, t_ray ray)
{
	t_hit	hit;

	if (cur->id == SPHERE)
		hit = hit_sphere(cur, ray);
	else if (cur->id == PLANE)
		hit = hit_plane(cur, ray);
	else
		hit = hit_cylinder(cur, ray);
	return (hit);
}

/*
page-38 https://www.cs.cornell.edu/courses/
cs4620/2014fa/lectures/04rt-intersect.pdf
*/
t_hit	hit_object(t_main *data, t_ray ray)
{
	t_object	*cur;
	t_hit		hit;
	t_hit		best;

	best.is_hit = 0;
	cur = data->obj;
	while (cur)
	{
		hit = get_hit(cur, ray);
		if (hit.is_hit)
		{
			if (!best.is_hit || hit.t < best.t)
			{
				best = hit;
				best.hit_obj = cur;
			}
		}
		cur = cur->next;
	}
	return (best);
}
