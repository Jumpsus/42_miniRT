#include "mini_rt.h"

int	rt_adjust_trans(int key, t_main *data){
	if (key == K_UP) {
		data->use_camera.eye = vector_add(data->use_camera.eye, data->use_camera.up);
	} else if (key == K_DOWN) {
		data->use_camera.eye = vector_subtract(data->use_camera.eye, data->use_camera.up);
	} else if (key == K_RIGHT) {
		data->use_camera.eye = vector_add(data->use_camera.eye, data->use_camera.right);
	} else if (key == K_LEFT) {
		data->use_camera.eye = vector_subtract(data->use_camera.eye, data->use_camera.right);
	} else if (key == K_LESS){
		data->use_camera.eye = vector_subtract(data->use_camera.eye, data->use_camera.forward);
	} else if (key == K_MORE){
		data->use_camera.eye = vector_add(data->use_camera.eye, data->use_camera.forward);
	}

	rt_render(data);
	return (0);
}

int	rt_adjust_rots(int key, t_main *data){

	if (key == K_W) {
		data->use_camera.pitch = data->use_camera.pitch - (M_PI / 36.0);
	} else if (key == K_S) {
		data->use_camera.pitch = data->use_camera.pitch + (M_PI / 36.0);
	} else if (key == K_A) {
		data->use_camera.yaw = data->use_camera.yaw + (M_PI / 36.0);
	} else if (key == K_D) {
		data->use_camera.yaw = data->use_camera.yaw - (M_PI / 36.0);
	}

	rt_render(data);
	return (0);
}

int	rt_adjust_zoom(int key, t_main *data){
	if (key == K_X) {
		if (data->use_camera.fov + 5.0 > 180.0){
			data->use_camera.fov = 180;
		} else {
			data->use_camera.fov += 5.0;
		}
	} else if (key == K_Z) {
		if (data->use_camera.fov - 5.0 < 0.0){
			data->use_camera.fov = 0;
		} else {
			data->use_camera.fov -= 5.0;
		}
	}
	rt_render(data);
	return (0);
}

int	rt_scroll(int key, t_main *data){
	if (data->select_obj.obj){
		if (key == M_UP)
			data->select_obj.obj->pos = vector_add(data->select_obj.obj->pos, data->use_camera.forward);
		if (key == M_DOWN)
			data->select_obj.obj->pos = vector_subtract(data->select_obj.obj->pos, data->use_camera.forward);
	} else {
		if (key == M_UP) {
			data->use_camera.fov += 5.0;
			if (data->use_camera.fov > 180.0)
				data->use_camera.fov = 180;
		} else if (key == M_DOWN) {
			data->use_camera.fov -= 5.0;
			if (data->use_camera.fov < 0.0)
				data->use_camera.fov = 0;
		}
	}
	return (0);
}

int	rt_set_obj_mode(int key, t_main *data){

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

int	rt_adjust_object(int key, t_main *data){

	int		adjust;

	if (!data->select_obj.obj && !data->select_obj.mode)
		return (0);
	adjust = 1;
	if (key == K_LESS)
		adjust = -1;

	if (data->select_obj.mode == 'h') {
		data->select_obj.obj->height += adjust * 1.0;
	} else if (data->select_obj.mode == 'r') {
		data->select_obj.obj->radius += adjust * 1.0;
	} else if (data->select_obj.mode == 'x') {
		rotate_object(data->select_obj.obj, adjust * M_PI / 36, 0, 0);
	} else if (data->select_obj.mode == 'y') {
		rotate_object(data->select_obj.obj, 0, adjust * M_PI / 36, 0);
	} else if (data->select_obj.mode == 'z') {
		rotate_object(data->select_obj.obj, 0, 0, adjust * M_PI / 36);
	} 

	rt_render(data);
	return (0);
}