#include "mini_rt.h"

/* https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection */
double  hit_plane(t_object *plane, t_ray ray)
{
    double  denom;
    double  t;

    denom = vector_dot(plane->norm, ray.dir);
    if (fabs(denom) > 1e-6){
        t = vector_dot(vector_subtract(plane->pos, ray.orig), plane->norm) / denom;
        return (t);
    }
    return (-1);
}

// t_color	ray_color_plane(t_object *plane, t_ray r)
// {
// 	double	t = hit_plane(plane, r);
// 	if (t > 0)
// 	{
// 		t_point	N = unit_vector(vector_subtract(ray_at(r, t), (t_point){0, 0, -1}));
//         return color_multiply((t_color){N.x+1, N.y+1, N.z+1}, 0.5);
// 	}
// 	t_point	unit_direction = unit_vector(r.dir);
// 	t = 0.5 * (unit_direction.y + 1.0);
// 	return (color_add(color_multiply((t_color){1, 1, 1}, 1.0 - t),
// 		color_multiply((t_color){.5, .7, 1}, t)));
// }

// void	render_plane(t_main *data)
// {
// 	t_point	horiz = (t_point){4,0,0};
// 	t_point	vert = (t_point){0,2,0};
// 	t_point lower_left = vector_subtract((t_point){0,0,0},
// 		vector_add(vector_add(vector_divide(horiz, 2),
// 			vector_divide(vert, 2)), (t_point){0,0,1}));
// 	t_ray	r;
// 	int		i, j;
// 	t_point	u, v;

// 	j = WINDOW_HEIGHT;
// 	while (--j >= 0)
// 	{
// 		i = 0;
// 		while (i < WINDOW_WIDTH)
// 		{
// 			u = vector_multiply(horiz, (double)i / (WINDOW_WIDTH - 1));
// 			v = vector_multiply(vert, (double)j / (WINDOW_HEIGHT - 1));
// 			r = (t_ray){(t_point){0,0,0}, vector_subtract(vector_add(
// 					lower_left, vector_add(u, v)), (t_point){0,0,0})};
// 			img_pix_put(&data->img, i, j, ray_color_plane(data->obj, r));
// 			i++;
// 		}
// 	}
// }