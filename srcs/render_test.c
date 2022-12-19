#include "mini_rt.h"

// t_color	ray_color(t_object *obj, t_ray r)
// {
// 	double	t;

// 	t = hit_object(obj, r);
// 	if (t > 0)
// 	{
// 		return ((t_color){ 1, 0, 0 });
// 	}
// 	return ((t_color){ 255, 0, 0 });
// }

t_color	ray_color(t_object *obj, t_ray r)
{
	double	t;
	
	t = hit_object(obj, r);
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

void	main_render(t_main *data)
{
	double	angle;
	int		i;
	int		j;
	double	xx;
	double	yy;

	angle = tan(M_PI * 0.5 * data->camera.fov / 180);
	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			xx = (2 * ((i + 0.5) / WINDOW_WIDTH) - 1)
				* angle * WINDOW_WIDTH / WINDOW_HEIGHT; 
			yy = (1 - 2 * ((j + 0.5) / WINDOW_HEIGHT)) * angle;
			img_pix_put(&data->img, i, j,
				ray_color(data->obj, create_ray(
					data->camera.pos, (t_point){xx, yy, -1})));
			i++;
		}
	}
}
