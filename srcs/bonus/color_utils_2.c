#include "color.h"

// source: https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-pixel.html
int	rgb_to_int(t_color color)
{
	int	c;

	c = 0;
	c |= (int)(color.b * 255);
	c |= (int)(color.g * 255) << 8;
	c |= (int)(color.r * 255) << 16;
	return (c);
}

t_color	color_normalize(t_color a)
{
	t_color	result;

	result = a;
	if (result.r > 1)
		result.r = 1;
	if (result.g > 1)
		result.g = 1;
	if (result.b > 1)
		result.b = 1;
	return (result);
}
