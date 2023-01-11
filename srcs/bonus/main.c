#include "mini_rt_bonus.h"

void	main_render(t_main *data);
void	camera_render(t_main *data);

void	rt_init(t_main *data, char *path)
{
	data->light = 0;
	data->obj = 0;
	scene_set_defalt(&data->ambient);
	scene_set_defalt(&data->camera);
	scene_read(data, path);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
		&data->img.line, &data->img.endian);
	data->background = (t_color){0, 0, 0};
	data->use_camera = create_camera(data->camera);
	data->select_obj.obj = 0;
	data->select_obj.mode = 0;
}

#ifdef __linux__

int	rt_clear(t_main *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	scene_clear(data);
	exit(EXIT_SUCCESS);
}

#else

int	rt_clear(t_main *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	scene_clear(data);
	exit(EXIT_SUCCESS);
}

#endif


int	rt_mouse(int key, int x, int y, t_main *data)
{	
	t_hit	hit;
	t_ray	ray;
	
	ray = make_ray_from_pixel(&(data->use_camera), x, y);
	if (key == M_LEFT) {
		hit = hit_object(data, ray);
		if (hit.is_hit)
			data->select_obj.obj = hit.hit_obj;
		// printf("selected object = %p", data->select_obj.obj);

	} else if (key == M_RIGHT) {
		data->select_obj.obj = 0; // unselect object
		data->select_obj.mode = 0; //unset mode
		// printf("unselected selected %p", data->select_obj.obj);

	} else if (key == M_UP || key == M_DOWN) {
		rt_scroll(key, data); // zoom in and out OR move obj fw and bw
	}

	printf("key : %d\n", key);
	rt_render(data);
	return (0);
}

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
		rt_set_obj_mode(key, data);// rt_adjust_zoom(key, data);
	if (key == K_LESS || key == K_MORE)
		rt_adjust_object(key, data);

	printf("key : %d\n", key);

	return (EXIT_SUCCESS);
}

int	rt_hi(int key, int x, int y, t_main *data)
{

	printf("key : %d %d %d %f\n", key, x, y, data->obj->norm.x);

	return (EXIT_SUCCESS);
}

int	rt_render(t_main *data)
{
	if (!data->win_ptr)
		return (1);
	// main_render(data);
	camera_render(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	data;

	if (argc != 2)
	{
		ft_putendl_fd("Error\ninvalid number of arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	rt_init(&data, argv[1]);

	mlx_hook(data.win_ptr, 17, 1L << 17, &rt_clear, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, &rt_key, &data);
	mlx_mouse_hook(data.win_ptr, &rt_mouse, &data);
	mlx_loop_hook(data.mlx_ptr, &rt_render, &data);
	mlx_loop(data.mlx_ptr);
}
