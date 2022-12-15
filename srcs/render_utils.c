#include "mini_rt.h"

void	img_pix_put(t_img *img, int x, int y, t_color color)
{
	char	*pixel;
	int		i;
	int		c;

	c = rgb_to_int(color);
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (c >> i) & 0xFF;
		else
			*pixel++ = (c >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
