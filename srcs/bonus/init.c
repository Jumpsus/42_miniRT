#include "mini_rt_bonus.h"

static void	obj_set_defalt(t_object *obj)
{
	obj->id = 0;
	obj->pos = (t_point){0, 0, 0};
	obj->color = (t_color){0, 0, 0};
	obj->norm = (t_point){0, 0, 0};
	obj->ratio = 0;
	obj->fov = 0;
	obj->radius = 0;
	obj->height = 0;
	obj->next = 0;
}

void	rt_init(t_main *data, char *path)
{
	data->light = 0;
	data->obj = 0;
	obj_set_defalt(&data->ambient);
	obj_set_defalt(&data->camera);
	scene_read(data, path);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line, &data->img.endian);
	data->background = (t_color){0, 0, 0};
	data->use_camera = init_camera(data->camera);
	data->select_obj.obj = 0;
	data->select_obj.mode = 0;
}

t_object	*init_obj(t_object **obj)
{
	if (!*obj)
	{
		*obj = malloc(sizeof(**obj));
		obj_set_defalt(*obj);
		return (*obj);
	}
	return (init_obj(&(*obj)->next));
}

t_camera	init_camera(t_object camera)
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
