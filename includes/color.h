/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:55 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 17:48:57 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color {
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	color_add(t_color a, t_color b);
t_color	color_substract(t_color a, t_color b);
t_color	color_multiply_color(t_color a, t_color b);
t_color	color_multiply_n(t_color a, double multiplier);
t_color	color_divide(t_color a, double divisor);
int		rgb_to_int(t_color color);
t_color	color_normalize(t_color a);

#endif
