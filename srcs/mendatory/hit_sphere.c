/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:52:42 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 12:52:43 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*
source: https://www.cl.cam.ac.uk/teaching/1999/
AGraphHCI/SMAG/node2.html#eqn:rectcylrayquad
*/
t_hit	hit_sphere(t_object *sp, t_ray r)
{
	t_hit	hit[2];
	t_point	x;
	double	a;
	double	b;
	double	c;

	x = vector_subtract(r.orig, sp->pos);
	a = vector_square_length(r.dir);
	b = 2 * vector_dot(x, r.dir);
	c = vector_square_length(x) - pow(sp->radius, 2);
	hit[0] = set_hit_property(solve_quadratic_minus(a, b, c), sp, r);
	hit[1] = set_hit_property(solve_quadratic_plus(a, b, c), sp, r);
	hit[0] = select_hit(hit[0], hit[1]);
	if (hit[0].is_hit)
		return (hit[0]);
	return (set_hit_property(-DBL_MAX, sp, r));
}
