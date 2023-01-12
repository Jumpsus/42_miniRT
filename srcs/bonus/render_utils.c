/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:41:09 by prrattan          #+#    #+#             */
/*   Updated: 2023/01/12 10:41:28 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

void	img_pix_put(t_img *img, int x, int y, t_color color)
{
	char	*pixel;
	int		i;
	int		c;

	c = rgb_to_int(color);
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (c >> i) & 0xFF;
		else
			*pixel++ = (c >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/*
	sample:

	t_point	rotate = (t_point){0.5, 0.75, 1};
	double	size = vector_length(rotate);
	rotate_object(obj,
		acos(rotate.x / size),
		acos(rotate.y / size),
		acos(rotate.z / size));
*/
void	rotate_object(t_object *obj, double x_rot, double y_rot, double z_rot)
{
	t_point	result;

	result.x = obj->norm.x * (cos(y_rot) * cos(z_rot))
		+ obj->norm.y * (sin(x_rot) * sin(y_rot)
			* cos(z_rot) - cos(x_rot) * sin(y_rot))
		+ obj->norm.z * (cos(x_rot) * sin(y_rot)
			* cos(z_rot) + sin(x_rot) * sin(y_rot));
	result.y = obj->norm.x * (cos(y_rot) * sin(z_rot))
		+ obj->norm.y * (sin(x_rot) * sin(y_rot)
			* sin(z_rot) + cos(x_rot) * cos(y_rot))
		+ obj->norm.z * (cos(x_rot) * sin(y_rot)
			* sin(z_rot) - sin(x_rot) * cos(y_rot));
	result.z = obj->norm.x * (-sin(y_rot))
		+ obj->norm.y * (sin(x_rot) * cos(y_rot))
		+ obj->norm.z * (cos(x_rot) * cos(y_rot));
	obj->norm = unit_vector(result);
}
