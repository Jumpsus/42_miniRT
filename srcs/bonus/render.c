#include "mini_rt_bonus.h"

int	rt_render(t_main *data)
{
	if (!data->win_ptr)
		return (1);
	camera_render(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	tutorial_render(data);
	return (0);
}

static void	set_camera(t_camera *c)
{
	double	x;
	double	y;
	double	z;

	x = cos(c->yaw) * cos(c->roll);
	y = sin(c->pitch) * sin(c->yaw) * cos(c->roll) - \
		cos(c->pitch) * sin(c->roll);
	z = cos(c->pitch) * sin(c->yaw) * cos(c->roll) + \
		sin(c->pitch) * sin(c->roll);
	c->right = create_vector(x, y, z);
	x = cos(c->yaw) * sin(c->roll);
	y = sin(c->pitch) * sin(c->yaw) * sin(c->roll) + \
		cos(c->pitch) * cos(c->roll);
	z = cos(c->pitch) * sin(c->yaw) * sin(c->roll) - \
		sin(c->pitch) * cos(c->roll);
	c->up = create_vector(x, y, z);
	x = 1.0 * sin(c->yaw);
	y = sin(c->pitch) * cos(c->yaw);
	z = cos(c->pitch) * cos(c->yaw);
	c->forward = create_vector(x, y, z);
	c->h = tan(M_PI * 0.5 * c->fov / 180);
	c->w = c->h * c->aspect_ratio;
	return ;
}

void	camera_render(t_main *data)
{
	t_ray		ray_cood;
	int			i;
	int			j;

	set_camera(&(data->use_camera));
	j = 0;
	while (j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			ray_cood = make_ray_from_pixel(&(data->use_camera), i, j);
			img_pix_put(&data->img, i, j, trace(data, ray_cood));
			i++;
		}
		j++;
	}
}

void	tutorial_render(t_main *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 15, 0xFFFFFF,
		"how to use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0xFFFFFF,
		"object grab    : right click");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 45, 0xFFFFFF,
		"object drop    : left click");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 60, 0xFFFFFF,
		"object resize  : H,R + <,>");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 75, 0xFFFFFF,
		"object rotation: X,Y,Z + <,>");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0xFFFFFF,
		"camera rotation: W,A,S,D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 105, 0xFFFFFF,
		"zoom           : scroll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 120, 0xFFFFFF,
		"translation    : up,left,down,right");
}
