#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <float.h>
# include "libft.h"

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_ray {
	t_point	orig;
	t_point	dir;
}	t_ray;

t_point		create_vector(double x, double y, double z);
t_point		vector_add(t_point a, t_point b);
t_point		vector_subtract(t_point a, t_point b);
t_point		vector_multiply(t_point a, double multiplier);
t_point		vector_divide(t_point a, double divisor);
double		vector_square_length(t_point a);
double		vector_length(t_point a);
double		vector_dot(t_point a, t_point b);
t_point		vector_cross(t_point a, t_point b);
t_point		unit_vector(t_point a);
t_point		rotate_vector(t_point v, double x_rot, double y_rot, double z_rot);
t_ray		create_ray(t_point orig, t_point dir);
t_point		ray_at(t_ray x, double t);

#endif
