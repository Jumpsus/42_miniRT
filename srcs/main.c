#include "mini_rt.h"

void	rt_init(t_main *data, char *path)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	map_read(data, path);
}

#ifdef __linux__

int	rt_clear(t_main *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	map_clear(data);
	exit(EXIT_SUCCESS);
}

#else

int	rt_clear(t_main *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	map_clear(data);
	exit(EXIT_SUCCESS);
}

#endif

int	rt_key(int key, t_main *data)
{
	if (key == K_ESC)
	{
		printf("EXIT\n");
		rt_clear(data);
	}
	return (EXIT_SUCCESS);
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
	//mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop(data.mlx_ptr);
}
