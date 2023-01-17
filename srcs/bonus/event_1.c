/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:13 by pratanac          #+#    #+#             */
/*   Updated: 2023/01/12 17:48:15 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt_bonus.h"

int	rt_key(int key, t_main *data)
{
	if (key == K_ESC)
	{
		printf("EXIT\n");
		rt_clear(data);
	}
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
		rt_adjust_trans(key, data);
	if (key == K_A || key == K_W || key == K_S || key == K_D)
		rt_adjust_rots(key, data);
	if (key == K_H || key == K_X || key == K_Y || key == K_Z || key == K_R)
		rt_set_obj_mode(key, data);
	if (key == K_LESS || key == K_MORE)
		rt_adjust_object(key, data);
	return (EXIT_SUCCESS);
}

int	rt_adjust_trans(int key, t_main *data)
{
	t_point		dir;

	if (key == K_DOWN || key == K_UP)
		dir = data->use_camera.up;
	else
		dir = data->use_camera.right;
	if (key == K_UP || key == K_RIGHT)
		dir = vector_multiply(dir, 1.0);
	else
		dir = vector_multiply(dir, -1.0);
	if (data->select_obj.obj)
		data->select_obj.obj->pos = vector_add(data->select_obj.obj->pos, dir);
	else
		data->use_camera.eye = vector_add(data->use_camera.eye, dir);
	return (0);
}

int	rt_adjust_rots(int key, t_main *data)
{
	if (key == K_W)
		data->use_camera.pitch = data->use_camera.pitch - (M_PI / 36.0);
	else if (key == K_S)
		data->use_camera.pitch = data->use_camera.pitch + (M_PI / 36.0);
	else if (key == K_A)
		data->use_camera.yaw = data->use_camera.yaw + (M_PI / 36.0);
	else if (key == K_D)
		data->use_camera.yaw = data->use_camera.yaw - (M_PI / 36.0);
	return (0);
}

static int	rt_adjust_zoom(int key, t_main *data)
{
	if (key == M_DOWN)
	{
		if (data->use_camera.fov + 5.0 > 180.0)
			data->use_camera.fov = 180;
		else
			data->use_camera.fov += 5.0;
	}
	else if (key == M_UP)
	{
		if (data->use_camera.fov - 5.0 < 0.0)
			data->use_camera.fov = 0;
		else
			data->use_camera.fov -= 5.0;
	}
	return (0);
}

int	rt_scroll(int key, t_main *data)
{
	t_point		pos;
	t_point		dir;

	if (data->select_obj.obj)
	{
		pos = data->select_obj.obj->pos;
		dir = data->use_camera.forward;
		if (key == M_UP)
			data->select_obj.obj->pos = vector_add(pos, dir);
		if (key == M_DOWN)
			data->select_obj.obj->pos = vector_subtract(pos, dir);
	}
	else
	{
		rt_adjust_zoom(key, data);
	}
	return (0);
}
