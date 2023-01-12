/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:57:24 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 12:57:24 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

static t_hit	hit_cone_cap(t_object *cy, t_ray r)
{
	t_ray		cy_ray;
	t_object	pl;
	t_hit		hit;

	cy_ray = create_ray(cy->pos, cy->norm);
	pl.pos = ray_at(cy_ray, cy->height / 2);
	pl.id = PLANE;
	pl.color = cy->color;
	pl.norm = cy->norm;
	hit = hit_plane(&pl, r);
	if (hit.is_hit)
		if (!(vector_square_length(vector_subtract(
						ray_at(r, hit.t), pl.pos)) < pow(cy->radius, 2)))
			hit.is_hit = 0;
	if (hit.is_hit)
		return (hit);
	return (set_hit_property(-DBL_MAX, cy, r));
}

static t_hit	hit_cone_surface_2(t_object *cy, t_ray r, t_hit hit[2])
{
	t_ray	cy_ray;
	t_point	p[2];
	t_point	q;
	int		i;

	cy_ray = create_ray(cy->pos, cy->norm);
	p[0] = ray_at(cy_ray, -cy->height / 2);
	p[1] = ray_at(cy_ray, cy->height / 2);
	i = -1;
	while (++i < 2)
	{
		if (hit[i].is_hit)
		{
			q = ray_at(r, hit[i].t);
			if (!(vector_dot(cy->norm, vector_subtract(q, p[0])) > 0
					&& vector_dot(cy->norm, vector_subtract(q, p[1])) < 0))
				hit[i].is_hit = 0;
		}
	}
	hit[0] = select_hit(hit[0], hit[1]);
	if (hit[0].is_hit)
		return (hit[0]);
	return (set_hit_property(-DBL_MAX, cy, r));
}

/*
https://hugi.scene.org/online/hugi24/coding%20graphics
%20chris%20dragan%20raytracing%20shapes.htm
*/
static t_hit	hit_cone_surface(t_object *cy, t_ray r)
{
	t_hit	hit[2];
	t_point	x;
	double	a;
	double	b;
	double	c;

	x = vector_subtract(r.orig, ray_at(
				create_ray(cy->pos, cy->norm), -cy->height / 2));
	a = vector_square_length(r.dir)
		- (1 + pow(cy->radius / cy->height, 2))
		* pow(vector_dot(r.dir, cy->norm), 2);
	b = 2 * (vector_dot(r.dir, x)
			- (1 + pow(cy->radius / cy->height, 2))
			* vector_dot(r.dir, cy->norm)
			* vector_dot(x, cy->norm));
	c = vector_square_length(x)
		- (1 + pow(cy->radius / cy->height, 2))
		* pow(vector_dot(x, cy->norm), 2);
	hit[0] = set_hit_property(solve_quadratic_minus(a, b, c), cy, r);
	hit[1] = set_hit_property(solve_quadratic_plus(a, b, c), cy, r);
	return (hit_cone_surface_2(cy, r, hit));
}

/*
https://mrl.cs.nyu.edu/~dzorin/rendering/lectures/lecture3/lecture3.pdf
*/
t_hit	hit_cone(t_object *cy, t_ray r)
{
	t_hit	hits;
	t_hit	hitc;
	t_hit	h;

	hits = hit_cone_surface(cy, r);
	hitc = hit_cone_cap(cy, r);
	h = select_hit(hits, hitc);
	if (h.is_hit)
		return (h);
	return (set_hit_property(-DBL_MAX, cy, r));
}
