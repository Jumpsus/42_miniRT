#include "mini_rt_bonus.h"

/* vector = vector_add(vector_add(cam.forward, 
vector_multiply(cam.right, u * cam.w)), 
vector_multiply(cam.up, v * cam.h)); */
t_ray	make_ray(t_camera cam, double u, double v)
{
	t_point	vector;

	vector = vector_add(cam.forward, vector_multiply(cam.right, u * cam.w));
	vector = vector_add(vector, vector_multiply(cam.up, v * cam.h));
	return (create_ray(cam.eye, unit_vector(vector)));
}

static t_point	get_direction(t_camera cam, double x, double y)
{
	double	p_x;
	double	p_y;

	p_x = ((2.0 * (x) / (double)WINDOW_WIDTH) - 1.0) * cam.w;
	p_y = (1.0 - (2.0 * (y) / (double)WINDOW_HEIGHT) * cam.h);
	return (create_vector(p_x, p_y, 1));
}

t_ray	make_ray_from_pixel(t_camera *cam, int x, int y)
{
	t_point	origin;
	t_point	d;

	origin = cam->eye;
	d = get_direction(*cam, x, y);
	d = create_vector(
			d.x * cam->right.x + d.y * cam->up.x + cam->forward.x,
			d.x * cam->right.y + d.y * cam->up.y + cam->forward.y,
			d.x * cam->right.z + d.y * cam->up.z + cam->forward.z
			);
	d = unit_vector(d);
	return (create_ray(origin, d));
}

void	img_pix_put(t_img *img, int x, int y, t_color color)
{
	char	*pixel;
	int		i;
	int		c;

	c = rgb_to_int(color);
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (c >> i) & 0xFF;
		else
			*pixel++ = (c >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
