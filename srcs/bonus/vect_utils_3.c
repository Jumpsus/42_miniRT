/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:13 by pratanac          #+#    #+#             */
/*   Updated: 2023/01/12 17:48:15 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_ray	create_ray(t_point orig, t_point dir)
{
	t_ray	result;

	result.orig = orig;
	result.dir = unit_vector(dir);
	return (result);
}

t_point	ray_at(t_ray x, double t)
{
	return (vector_add(x.orig, vector_multiply(x.dir, t)));
}
