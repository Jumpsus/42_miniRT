/* just a test for rendering sphere */

#include "mini_rt.h"

// t_point	ray_at(t_ray x, double t)
// {
//     return (vector_add(x.orig, vector_multiply(x.dir, t)));
// }

int	hit_sphere(t_object *sphere, t_ray r)
{
	t_point	oc = vector_subtract(r.orig, sphere->pos);
	double	a = vector_square_length(r.dir);
	double	half_b = vector_dot(oc, r.dir);
    // double	c = vector_square_length(oc) - pow(0.5 * sphere->diam, 2);
	double c = 1;
	double	discriminant = pow(half_b, 2) - a * c;
	if (discriminant < 0)
		return (-1);
	return ((-half_b - sqrt(discriminant)) / a);
}

t_color	ray_color(t_object *sphere, t_ray r)
{
	double	t = hit_sphere(sphere, r);
	if (t > 0)
	{
		t_point	N = unit_vector(vector_subtract(ray_at(r, t), (t_point){0, 0, -1}));
        return color_multiply((t_color){N.x+1, N.y+1, N.z+1}, 0.5);
	}
	t_point	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (color_add(color_multiply((t_color){1, 1, 1}, 1.0 - t),
		color_multiply((t_color){.5, .7, 1}, t)));
}

void	render_sphere(t_main *data)
{
	t_point	horiz = (t_point){4,0,0};
	t_point	vert = (t_point){0,2,0};
	t_point lower_left = vector_subtract((t_point){0,0,0},
		vector_add(vector_add(vector_divide(horiz, 2),
			vector_divide(vert, 2)), (t_point){0,0,1}));
	t_ray	r;
	int		i, j;
	t_point	u, v;

	j = WINDOW_HEIGHT;
	while (--j >= 0)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			u = vector_multiply(horiz, (double)i / (WINDOW_WIDTH - 1));
			v = vector_multiply(vert, (double)j / (WINDOW_HEIGHT - 1));
			r = (t_ray){(t_point){0,0,0}, vector_subtract(vector_add(
					lower_left, vector_add(u, v)), (t_point){0,0,0})};
			img_pix_put(&data->img, i, j, ray_color(data->obj, r));
			i++;
		}
	}
}
