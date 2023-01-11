#include "mini_rt_bonus.h"

int	rt_mouse(int key, int x, int y, t_main *data)
{	
	t_hit	hit;
	t_ray	ray;

	ray = make_ray_from_pixel(&(data->use_camera), x, y);
	if (key == M_LEFT)
	{
		hit = hit_object(data, ray);
		if (hit.is_hit)
			data->select_obj.obj = hit.hit_obj;
	}
	else if (key == M_RIGHT)
	{
		data->select_obj.obj = 0;
		data->select_obj.mode = 0;
	}
	else if (key == M_UP || key == M_DOWN)
	{
		rt_scroll(key, data);
	}
	rt_render(data);
	return (0);
}

int	rt_set_obj_mode(int key, t_main *data)
{
	if (!data->select_obj.obj)
		return (0);
	if (key == K_H)
		data->select_obj.mode = 'h';
	if (key == K_X)
		data->select_obj.mode = 'x';
	if (key == K_Y)
		data->select_obj.mode = 'y';
	if (key == K_Z)
		data->select_obj.mode = 'z';
	if (key == K_R)
		data->select_obj.mode = 'r';
	return (0);
}

int	rt_adjust_object(int key, t_main *data)
{
	int		adjust;

	if (!data->select_obj.obj && !data->select_obj.mode)
		return (0);
	adjust = 1;
	if (key == K_LESS)
		adjust = -1;
	if (data->select_obj.mode == 'h')
		data->select_obj.obj->height += adjust * 1.0;
	else if (data->select_obj.mode == 'r')
		data->select_obj.obj->radius += adjust * 1.0;
	else if (data->select_obj.mode == 'x')
		rotate_object(data->select_obj.obj, adjust * M_PI / 36, 0, 0);
	else if (data->select_obj.mode == 'y')
		rotate_object(data->select_obj.obj, 0, adjust * M_PI / 36, 0);
	else if (data->select_obj.mode == 'z')
		rotate_object(data->select_obj.obj, 0, 0, adjust * M_PI / 36);
	rt_render(data);
	return (0);
}
