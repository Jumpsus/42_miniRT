#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
// # include "libft.h"
# include "key.h"

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_ray {
	t_point	orig; // origin
	t_point	dir; // direction
}	t_ray;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

typedef struct s_main {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_main;

#endif
