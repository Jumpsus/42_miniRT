#include "vector.h"

int	is_vector_equal(t_point a, t_point b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

/* source: https://en.wikipedia.org/wiki/Rotation_matrix */
t_point	rotate_vector(t_point v, double x_rot, double y_rot, double z_rot)
{
	t_point	result;
	double	x;
	double	y;
	double	z;

	x = v.x;
	y = v.y * cos(x_rot) - v.z * sin(x_rot);
	z = v.y * sin(x_rot) + v.z * cos(x_rot);
	result = create_vector(x, y, z);
	x = v.x * cos(y_rot) + v.z * sin(y_rot);
	y = v.y;
	z = v.z * cos(y_rot) - v.x * sin(y_rot);
	result = create_vector(x, y, z);
	x = v.x * cos(z_rot) - v.y * sin(z_rot);
	y = v.x * sin(z_rot) + v.y * cos(z_rot);
	z = v.z;
	result = create_vector(x, y, z);
	return (result);
}

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
