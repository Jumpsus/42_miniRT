#include "mini_rt.h"

/*
https://www.scratchapixel.com/lessons/3d-basic-rendering/
minimal-ray-tracer-rendering-simple-shapes/
ray-plane-and-ray-disk-intersection
*/
t_hit	hit_plane(t_object *pl, t_ray ray)
{
	double	denom;
	double	t;

	denom = vector_dot(pl->norm, ray.dir);
	if (fabs(denom) > 1e-6)
	{
		t = vector_dot(vector_subtract(pl->pos, ray.orig), pl->norm) / denom;
		return (set_hit_property(t, pl, ray));
	}
	return (set_hit_property(-DBL_MAX, pl, ray));
}
