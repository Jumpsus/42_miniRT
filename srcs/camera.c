#include "mini_rt.h"

t_camera	create_camera(t_object camera)
{
	t_camera	cam;

	cam.eye = camera.pos;
	cam.aspect_ratio = WINDOW_WIDTH / WINDOW_HEIGHT;
	cam.fov = camera.fov;
	cam.roll = 0.0;
	cam.pitch = asin(-1.0 * camera.norm.y);
	cam.yaw = atan2(camera.norm.x, camera.norm.z);

	return (cam);
}

// static t_camera	make_camera(t_object camera)
// {
// 	t_camera	cam;
// 	double	  aspect_ratio;
// 	t_point	 upguide;

// 	upguide = create_vector(0.0, 1.0, 0.0);

// 	aspect_ratio = WINDOW_WIDTH/WINDOW_HEIGHT;
// 	cam.eye = camera.pos;
// 	cam.forward = unit_vector(camera.norm);
// 	cam.right = unit_vector(vector_cross(upguide, cam.forward));
// 	cam.up = vector_cross(cam.forward, cam.right);
// 	cam.h = tan(M_PI * 0.5 * camera.fov / 180);
// 	cam.w = cam.h * aspect_ratio;

// 	printf("FORWARD : %f %f %f\n", cam.forward.x, cam.forward.y, cam.forward.z);
// 	printf("RIGHT : %f %f %f\n", cam.right.x, cam.right.y, cam.right.z);
// 	printf("UP : %f %f %f\n", cam.up.x, cam.up.y, cam.up.z);

// 	return (cam);
// }

static void	set_camera(t_camera *c)
{
	c->right = create_vector(cos(c->yaw) * cos(c->roll), sin(c->pitch) * sin(c->yaw) * cos(c->roll) - cos(c->pitch) * sin(c->roll),  cos(c->pitch) * sin(c->yaw) * cos(c->roll) + sin(c->pitch) * sin(c->roll));
	c->up = create_vector(cos(c->yaw) * sin(c->roll), sin(c->pitch) * sin(c->yaw) * sin(c->roll) + cos(c->pitch) * cos(c->roll), cos(c->pitch) * sin(c->yaw) * sin(c->roll) - sin(c->pitch) * cos(c->roll));
	c->forward = create_vector(-1.0 * sin(c->yaw), sin(c->pitch) * cos(c->yaw), cos(c->pitch) * cos(c->yaw));
	
	c->h = tan(M_PI * 0.5 * c->fov / 180);
	c->w = c->h * c->aspect_ratio;

	return ;
}

t_ray   make_ray(t_camera cam, double u, double v)
{
	t_point vector;
	
	vector = vector_add(vector_add(cam.forward, vector_multiply(cam.right, u * cam.w)), vector_multiply(cam.up, v * cam.h));
	return create_ray(cam.eye, unit_vector(vector));
}

static t_point get_direction(t_camera cam, double x, double y)
{
	double	  p_x;
	double	  p_y;

	p_x = ((2.0 * (x) / (double)WINDOW_WIDTH) - 1.0) * cam.w;
	p_y = (1.0 - (2.0 * (y) / (double)WINDOW_HEIGHT) * cam.h);

	return create_vector(p_x, p_y, 1);
}

t_ray   make_ray_from_pixel(t_camera *cam, int x, int y)
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
