/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:02:36 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 13:02:37 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r + b.r;
	result.g = a.g + b.g;
	result.b = a.b + b.b;
	return (result);
}

t_color	color_substract(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r - b.r;
	result.g = a.g - b.g;
	result.b = a.b - b.b;
	return (result);
}

t_color	color_multiply_color(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r * b.r;
	result.g = a.g * b.g;
	result.b = a.b * b.b;
	return (result);
}

t_color	color_multiply_n(t_color a, double multiplier)
{
	t_color	result;

	result.r = a.r * multiplier;
	result.g = a.g * multiplier;
	result.b = a.b * multiplier;
	return (result);
}

t_color	color_divide(t_color a, double divisor)
{
	return (color_multiply_n(a, (1 / divisor)));
}
