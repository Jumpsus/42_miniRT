#include "mini_rt.h"

double	hit_object(t_object *obj, t_ray ray)
{
	double	t;

	if (obj->id == SPHERE)
		t = hit_sphere(*obj, ray);
	// else if (obj->id == PLANE)
	// 	t = hit_plane(*obj, ray);
	else if (obj->id == CYLINDER)
		t = hit_cylinder(*obj, ray);
	return (t);
	// if (!obj->next)
	// 	return (t);
	// return (hit_object(obj->next, ray));
}

double	solve_quadratic_minus(double a, double b, double c)
{
	double	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (-DBL_MAX);
	return ((-b - sqrt(discriminant)) / (2 * a));
}

double	solve_quadratic_plus(double a, double b, double c)
{
	double	discriminant;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (-DBL_MAX);
	return ((-b + sqrt(discriminant)) / (2 * a));
}
