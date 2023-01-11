#ifndef COLOR_H
# define COLOR_H

typedef struct s_color {
	double	r;
	double	g;
	double	b;
}	t_color;

int		rgb_to_int(t_color color);
t_color	color_add(t_color a, t_color b);
t_color	color_substract(t_color a, t_color b);
t_color	color_multiply_color(t_color a, t_color b);
t_color	color_multiply_n(t_color a, double multiplier);
t_color	color_divide(t_color a, double divisor);
t_color	color_normalize(t_color a);

#endif
