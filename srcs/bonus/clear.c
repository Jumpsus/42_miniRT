#include "mini_rt_bonus.h"

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

void	scene_clear(t_main *data)
{
	t_object	*cur;
	t_object	*next;

	cur = data->obj;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}
