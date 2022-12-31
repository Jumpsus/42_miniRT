#include "mini_rt.h"

void	main_render(t_main *data);
void	camera_render(t_main *data);

void	rt_init(t_main *data, char *path)
{
	data->obj = 0;
	scene_set_defalt(&data->ambient);
	scene_set_defalt(&data->camera);
	scene_set_defalt(&data->light);
	scene_read(data, path);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
		&data->img.line, &data->img.endian);
	data->background = (t_color){0, 0, 0};
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

int	rt_adjust_trans(int key, t_main *data){
	if (key == K_UP) {
		data->camera.pos = vector_add(data->camera.pos, data->use_camera.up);
	} else if (key == K_DOWN) {
		data->camera.pos = vector_subtract(data->camera.pos, data->use_camera.up);
	} else if (key == K_RIGHT) {
		data->camera.pos = vector_add(data->camera.pos, data->use_camera.right);
	} else if (key == K_LEFT) {
		data->camera.pos = vector_subtract(data->camera.pos, data->use_camera.right);
	}
	rt_render(data);
	return (0);
}

int	rt_adjust_rots(int key, t_main *data){
	if (key == K_W) {
		data->camera.norm = unit_vector(vector_add(data->camera.norm, vector_multiply(data->use_camera.up, 0.1)));
	} else if (key == K_S) {
		data->camera.norm = unit_vector(vector_subtract(data->camera.norm, vector_multiply(data->use_camera.up, 0.1)));
	} else if (key == K_A) {
		data->camera.norm = unit_vector(vector_subtract(data->camera.norm, vector_multiply(data->use_camera.right, 0.1)));
	} else if (key == K_D) {
		data->camera.norm = unit_vector(vector_add(data->camera.norm, vector_multiply(data->use_camera.right, 0.1)));
	}
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
	{
		rt_adjust_trans(key, data);
	}

	if (key == K_A || key == K_W || key == K_S || key == K_D)
	{
		rt_adjust_rots(key, data);
	}

	// else if (key == K_UP){
	// 	printf("UP X:%f y:%f z:%f\n", data->use_camera.up.x, data->use_camera.up.y, data->use_camera.up.z);
	// 	data->camera.norm.x = data->camera.norm.x + data->use_camera.up.x * 0.1;
	// 	data->camera.norm.y = data->camera.norm.y + data->use_camera.up.y * 0.1;
	// 	data->camera.norm.z = data->camera.norm.z + data->use_camera.up.z * 0.1;
	// 	rt_render(data);
	// }
	// else if (key == K_DOWN){
	// 	printf("DOWN X:%f y:%f z:%f\n", data->use_camera.up.x, data->use_camera.up.y, data->use_camera.up.z);
	// 	data->camera.norm.x = data->camera.norm.x - data->use_camera.up.x * 0.1;
	// 	data->camera.norm.y = data->camera.norm.y - data->use_camera.up.y * 0.1;
	// 	data->camera.norm.z = data->camera.norm.z - data->use_camera.up.z * 0.1;
	// 	rt_render(data);
	// }
	// else if (key == K_RIGHT){
	// 	printf("RIGHT \n");
	// 	data->camera.norm.x = data->camera.norm.x + data->use_camera.right.x * 0.1;
	// 	data->camera.norm.y = data->camera.norm.y + data->use_camera.right.y * 0.1;
	// 	data->camera.norm.z = data->camera.norm.z + data->use_camera.right.z * 0.1;
	// 	rt_render(data);
	// } else if (key == K_LEFT){
	// 	printf("LEFT \n");
	// 	data->camera.norm.x = data->camera.norm.x - data->use_camera.right.x * 0.1;
	// 	data->camera.norm.y = data->camera.norm.y - data->use_camera.right.y * 0.1;
	// 	data->camera.norm.z = data->camera.norm.z - data->use_camera.right.z * 0.1;
	// 	rt_render(data);
	// }
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
	mlx_loop_hook(data.mlx_ptr, &rt_render, &data);
	mlx_loop(data.mlx_ptr);
}
