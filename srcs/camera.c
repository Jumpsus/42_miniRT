#include "mini_rt.h"

static t_camera	make_camera(t_object camera)
{
	t_camera	cam;
	double	  aspect_ratio;
	t_point	 upguide;

	upguide = create_vector(0.0, 1.0, 0.0);

	aspect_ratio = WINDOW_WIDTH/WINDOW_HEIGHT;
	cam.eye = camera.pos;
	cam.forward = unit_vector(camera.norm);
	cam.right = unit_vector(vector_cross(upguide, cam.forward));
	cam.up = vector_cross(cam.forward, cam.right);
	cam.h = tan(M_PI * 0.5 * camera.fov / 180);
	cam.w = cam.h * aspect_ratio;

	return (cam);
}

//	 vector = forward + (u * cam.w) * up_vector + (v * cam.h) * right_vector;
//	 u and v are cood
t_ray   make_ray(t_camera cam, double u, double v)
{
	t_point vector;
	
	vector = vector_add(vector_add(cam.forward, vector_multiply(cam.right, u * cam.w)), vector_multiply(cam.up, v * cam.h));
	// vector = vector_subtract(vector, cam.eye);
	return create_ray(cam.eye, unit_vector(vector));
}

static t_point get_direction(t_camera cam, double x, double y)
{
	double	  p_x;
	double	  p_y;

	// printf("x %f , y %f \n", x, y);

	p_x = ((2.0 * (x) / (double)WINDOW_WIDTH) - 1.0) * cam.w;
	p_y = (1.0 - (2.0 * (y) / (double)WINDOW_HEIGHT) * cam.h);

	return create_vector(p_x, p_y, 1);
}

static t_ray   make_ray_from_pixel(t_camera *cam, int x, int y)
{
	t_point	origin;
	t_point	direction;

	origin = cam->eye;
	direction = get_direction(*cam, x, y);
	direction = create_vector(
		direction.x * cam->right.x + direction.y * cam->up.x + cam->forward.x,
		direction.x * cam->right.y + direction.y * cam->up.y + cam->forward.y,
		direction.x * cam->right.z + direction.y * cam->up.z + cam->forward.z
	);
	direction = unit_vector(direction);

	return create_ray(origin, direction);
}

void	camera_render(t_main *data)
{
	t_ray		ray_cood;
	t_camera	cam;
	int			i;
	int			j;

	cam = make_camera(data->camera);
	j = 0;
	while (j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			// ray_cood = make_ray(cam, (2.0 * i / WINDOW_WIDTH) - 1.0, (-2.0 * j / WINDOW_HEIGHT) + 1.0);
			ray_cood = make_ray_from_pixel(&cam, i, j);
			img_pix_put(&data->img, i, j, trace(data, ray_cood));
			i++;
		}
		j++;
	}
}
