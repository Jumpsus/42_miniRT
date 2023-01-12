#include "mini_rt.h"

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
