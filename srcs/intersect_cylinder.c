#include "mini_rt.h"

// source: https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
double	hit_cylinder(t_object cy, t_ray r)
{
	t_ray	cy_ray;
	t_point	x;
	double	dv, xv, t1, t2, m1, m2;

	cy_ray = create_ray(cy.pos, cy.norm);
	x = vector_subtract(r.orig,
		ray_at(cy_ray, -cy.height / 2));
	dv = vector_dot(r.dir, cy.norm);
	xv = vector_dot(x, cy.norm);
	t1 = solve_quadratic_minus(
		vector_square_length(r.dir) - pow(dv, 2),
		2 * (vector_dot(r.dir, x) - dv * xv),
		vector_square_length(x) - pow(xv, 2) - pow(cy.radius, 2));
	t2 = solve_quadratic_plus(
		vector_square_length(r.dir) - pow(dv, 2),
		2 * (vector_dot(r.dir, x) - dv * xv),
		vector_square_length(x) - pow(xv, 2) - pow(cy.radius, 2));
	if (t1 == -DBL_MAX && t2 == -DBL_MAX)
		return (-DBL_MAX);

	m1 = dv * t1 + xv;
	m2 = dv * t2 + xv;

	if (m1 >= 0 && m1 <= cy.height)
		return m1;
	if (m2 >= 0 && m2 <= cy.height)
		return m2;

	/*
		The code below is for cylinder's cap,
		but I'm just guessing based on this sentence
		"Note that the ray may intersect both end caps, for example when z1 < z_min and z2 > z_max." 
		source: https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html#SECTION00023200000000000000
	*/
	if ((t2 != -DBL_MAX && m2 < 0) && m1 > cy.height)
		return m1;
	if ((t1 != -DBL_MAX && m1 < 0) && m2 > cy.height)
		return m2;
	return (-DBL_MAX);
}
