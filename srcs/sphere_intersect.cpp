#include "mini_rt.h"

// source: https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html#eqn:rectcylrayquad
double	hit_sphere(t_object sp, t_ray r)
{
	t_point	x;
	double	t1;
	double	t2;

	x = vector_subtract(r.orig, sp.pos);
	t1 = solve_quadratic_minus(
		vector_square_length(r.dir),
		2 * vector_dot(x, r.dir),
		vector_square_length(x) - pow(sp.radius, 2));
	t2 = solve_quadratic_plus(
		vector_square_length(r.dir),
		2 * vector_dot(x, r.dir),
		vector_square_length(x) - pow(sp.radius, 2));
	if (t1 == -DBL_MAX && t2 == -DBL_MAX)
		return (-DBL_MAX);
	// source: https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html#SECTION00023100000000000000
	if (t1 >= 0 && t1 <= t2)
		return (t1);
	if (t2 >= 0 && t2 < t1)
		return (t2);
	return (-DBL_MAX);
}
