/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:13 by pratanac          #+#    #+#             */
/*   Updated: 2023/01/12 17:48:15 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vector_square_length(t_point a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

double	vector_length(t_point a)
{
	return (sqrt(vector_square_length(a)));
}

double	vector_dot(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point	vector_cross(t_point a, t_point b)
{
	t_point	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

t_point	unit_vector(t_point a)
{
	t_point	result;

	if (vector_length(a) == 0)
		return (a);
	result.x = a.x / vector_length(a);
	result.y = a.y / vector_length(a);
	result.z = a.z / vector_length(a);
	return (result);
}
