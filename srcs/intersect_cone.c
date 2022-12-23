#include "mini_rt.h"

/* https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm */
double	hit_cone(t_object *cone, t_ray ray)
{
	double	a;
	double	half_b;
    double	c;
	double	k;
    t_point x;

    x = vector_subtract(ray.orig, cone->pos);
	k = tan((cone->angle / 2) * M_PI / 180.0);

	a = vector_dot(ray.dir, ray.dir) - (1.0 + pow(k, 2.0)) * pow(vector_dot(ray.dir, cone->norm),2.0);
    half_b = vector_dot(ray.dir, x) - (1.0 + pow(k, 2.0)) * vector_dot(ray.dir, cone->norm) * vector_dot(x, cone->norm);
    c = vector_dot(x, x) - (1.0 + pow(k, 2.0)) * pow(vector_dot(x, cone->norm),2.0);

    double	discriminant = pow(half_b, 2) - a * c;
	printf("a:%f b:%f c:%f discriminant: %f ",a,half_b,c, discriminant);
	if (discriminant < 0)
		return (-1);
	printf("t: %f \n", (-half_b - sqrt(discriminant)) / a);
	return ((-half_b - sqrt(discriminant)) / a);
}

t_color	ray_color_cone(t_object *cone, t_ray r)
{
	double	t = hit_cone(cone, r);
	if (t > 0)
	{
		// t_point	N = unit_vector(vector_subtract(ray_at(r, t), (t_point){0, 0, -1}));
        return color_multiply((t_color){1, 0, 0}, 0.5);
	}
	t_point	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return ((t_color){1, 1, 1});
}

void	render_cone(t_main *data)
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
			img_pix_put(&data->img, i, j, ray_color_cone(data->obj, r));
			i++;
		}
	}
}