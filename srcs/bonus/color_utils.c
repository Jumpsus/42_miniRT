#include "mini_rt_bonus.h"

// source: https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-pixel.html
int rgb_to_int(t_color color)
{
    int	c;

	c = 0;
    c |= (int)(color.b * 255);
    c |= (int)(color.g * 255) << 8;
    c |= (int)(color.r * 255) << 16;
    return (c);
}

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
