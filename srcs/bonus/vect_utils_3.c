# include "vector.h"

int	is_zero(t_point vector)
{
	return (vector.x == 0 && vector.y == 0 && vector.z == 0);
}

/* source: https://en.wikipedia.org/wiki/Rotation_matrix */
t_point	rotate_vector(t_point v, double x_rot, double y_rot, double z_rot)
{
	t_point	result;

	result = create_vector(v.x, v.y * cos(x_rot) - v.z * sin(x_rot), v.y * sin(x_rot) + v.z * cos(x_rot));
	result = create_vector(v.x * cos(y_rot) + v.z * sin(y_rot), v.y, v.z * cos(y_rot) - v.x * sin(y_rot));
	result = create_vector(v.x * cos(z_rot) - v.y * sin(z_rot), v.x * sin(z_rot) + v.y * cos(z_rot), v.z);
	return (result);
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
// void	rotate_object(t_object *obj, double x_rot, double y_rot, double z_rot)
// {
// 	t_point result;

// 	result.x = obj->norm.x * (cos(y_rot) * cos(z_rot))
// 		+ obj->norm.y * (sin(x_rot) * sin(y_rot) * cos(z_rot) - cos(x_rot) * sin(y_rot))
// 		+ obj->norm.z * (cos(x_rot) * sin(y_rot) * cos(z_rot) + sin(x_rot) * sin(y_rot));
// 	result.y = obj->norm.x * (cos(y_rot) * sin(z_rot))
// 		+ obj->norm.y * (sin(x_rot) * sin(y_rot) * sin(z_rot) + cos(x_rot) * cos(y_rot))
// 		+ obj->norm.z * (cos(x_rot) * sin(y_rot) * sin(z_rot) - sin(x_rot) * cos(y_rot));
// 	result.z = obj->norm.x * (-sin(y_rot))
// 		+ obj->norm.y * (sin(x_rot) * cos(y_rot))
// 		+ obj->norm.z * (cos(x_rot) * cos(y_rot));
// 	obj->norm = unit_vector(result);
// }

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
