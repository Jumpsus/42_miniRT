#include "mini_rt.h"

static t_color	diffuse_reflection(t_main *data, t_hit hit, t_point l_dir)
{
	t_color	light;
	double	nl;

	nl = vector_dot(hit.hit_norm, l_dir);
	if (nl < 0)
		nl = 0;
	light = color_multiply_n(data->light.color,
			data->light.ratio * nl);
	return (light);
}

/*
until page-17 https://www.cs.cornell.edu/courses/
cs4620/2014fa/lectures/05rt-shading.pdf
*/
static t_color	get_shaded_color(t_main *data, t_hit hit)
{
	t_point	l_dir;
	t_ray	l_ray;
	t_color	light;

	light = color_multiply_n(data->ambient.color, data->ambient.ratio);
	l_dir = unit_vector(vector_subtract(data->light.pos, hit.hit_pos));
	l_ray = create_ray(hit.hit_pos, l_dir);
	l_ray = create_ray(ray_at(l_ray, 1e-5), l_dir);
	if (!hit_object(data, l_ray).is_hit)
		light = color_add(light, diffuse_reflection(data, hit, l_dir));
	return (color_normalize(color_multiply_color(hit.hit_obj->color, light)));
}

t_color	trace(t_main *data, t_ray r)
{
	t_hit	hit;

	hit = hit_object(data, r);
	if (hit.is_hit)
		return (get_shaded_color(data, hit));
	return (data->background);
}
