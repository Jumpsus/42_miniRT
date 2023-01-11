#include "mini_rt.h"

static t_hit	get_hit(t_object *cur, t_ray ray)
{
	t_hit	hit;

	if (cur->id == SPHERE)
		hit = hit_sphere(cur, ray);
	else if (cur->id == PLANE)
		hit = hit_plane(cur, ray);
	else if (cur->id == CYLINDER)
		hit = hit_cylinder(cur, ray);
	return (hit);
}

// page-38 https://www.cs.cornell.edu/courses/cs4620/2014fa/lectures/04rt-intersect.pdf
t_hit	hit_object(t_main *data, t_ray ray)
{
	t_object	*cur;
	t_hit		hit;
	t_hit		best;

	best.is_hit = 0;
	cur = data->obj;
	while (cur)
	{
		// if (cur->id == SPHERE)
		// 	hit = hit_sphere(cur, ray);
		// else if (cur->id == PLANE)
		// 	hit = hit_plane(cur, ray);
		// else if (cur->id == CYLINDER)
		// 	hit = hit_cylinder(cur, ray);
		hit = get_hit(cur, ray);
		if (hit.is_hit)
		{
			if (!best.is_hit || hit.t < best.t)
			{
				best = hit;
				best.hit_obj = cur;
			}
		}
		cur = cur->next;
	}
	return (best);
}
