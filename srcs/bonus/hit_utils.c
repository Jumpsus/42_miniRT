#include "mini_rt_bonus.h"

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

static t_point	set_norm_cy_co(double t, t_object *obj, t_ray r)
{
	t_point	pc;
	t_point	hit_norm;

	pc = vector_subtract(ray_at(r, t),
		ray_at(create_ray(obj->pos, obj->norm), -obj->height / 2));
	if (obj->id == CYLINDER)
		hit_norm = vector_subtract(pc,
			vector_multiply(obj->norm, vector_dot(obj->norm, pc)));
	else
		hit_norm = vector_subtract(pc,
			vector_multiply(obj->norm, vector_dot(obj->norm, pc)
			* (1 + pow(obj->radius / obj->height, 2))));
	return (unit_vector(hit_norm));
}

t_hit	set_hit_property(double t, t_object *obj, t_ray r)
{
	t_hit	p;

	p.t = t;
	p.is_hit = (t >= 0);
	if (p.is_hit)
	{
		p.hit_pos = ray_at(r, t);
		if (obj->id == SPHERE)
			p.hit_norm = unit_vector(vector_subtract(p.hit_pos, obj->pos));
		else if (obj->id == PLANE)
			p.hit_norm = obj->norm;
		// https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
		else if (obj->id == CYLINDER || obj->id == CONE)
			p.hit_norm = set_norm_cy_co(t, obj, r);
	}
	return (p);
}

t_hit	select_hit(t_hit a, t_hit b)
{
	if (a.is_hit && b.is_hit)
	{
		if (a.t < b.t)
			return a;
		return b;
	}
	if (a.is_hit)
		return a;
	if (b.is_hit)
		return b;
	a.is_hit = 0;
	return a;
}
