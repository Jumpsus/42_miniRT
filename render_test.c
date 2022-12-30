#include "mini_rt.h"

void	main_render(t_main *data)
{
	double	angle;
	int		i;
	int		j;
	double	xx;
	double	yy;

	angle = tan(M_PI * 0.5 * data->camera.fov / 180);
	j = -1;
	while (++j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
			xx = (2 * ((i + 0.5) / WINDOW_WIDTH) - 1)
				* angle * WINDOW_WIDTH / WINDOW_HEIGHT; 
			yy = (1 - 2 * ((j + 0.5) / WINDOW_HEIGHT)) * angle;
			img_pix_put(&data->img, i, j,
				trace(data, create_ray(
					data->camera.pos, (t_point){xx, yy, -1})));
			i++;
		}
	}
}
