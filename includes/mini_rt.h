#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include <mlx.h>
# include "libft.h"
# include "key.h"

# define WINDOW_WIDTH	1200
# define WINDOW_HEIGHT	600

# define AMBIENT	1
# define CAMERA		2
# define LIGHT		3
# define SPHERE		4
# define PLANE		5
# define CYLINDER	6

typedef struct s_color {
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_ray {
	t_point	orig; // origin
	t_point	dir;  // direction (must always be a unit vector)
}	t_ray;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

typedef struct s_object {
	int				id;     // for all objects
	t_point			pos;    // for all objects except ambient
	t_color			color;  // for all objects except camera
	t_point			norm;   // (normalized) for camera, plane and cylinder
	double			ratio;  // for ambient and light
	double			fov;   	// for camera
	double			radius; // for sphere and cylinder
	double			height; // for cylinder
	// double			half_ang; // half angle use for cone
	struct s_object	*next;
}	t_object;

typedef struct s_main {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_object	ambient;
	t_object	camera;
	t_object	light;
	t_object	*obj;
}	t_main;

void	rt_init(t_main *data, char *path);
int		rt_clear(t_main *data);
int		rt_key(int key, t_main *data);
int		rt_render(t_main *data);

void	img_pix_put(t_img *img, int x, int y, t_color color);

t_point     create_vector(double x, double y, double z);
t_point		vector_add(t_point a, t_point b);
t_point		vector_subtract(t_point a, t_point b);
t_point		vector_multiply(t_point a, double multiplier);
t_point		vector_divide(t_point a, double divisor);
double		vector_square_length(t_point a);
double		vector_length(t_point a);
double		vector_dot(t_point a, t_point b);
t_point		vector_cross(t_point a, t_point b);
t_point		unit_vector(t_point a);
t_point		rotate_vector(t_point v, double x_rot, double y_rot, double z_rot);
t_ray		create_ray(t_point orig, t_point dir);
t_point		ray_at(t_ray x, double t);

int		rgb_to_int(t_color color);
t_color	color_add(t_color a, t_color b);
t_color	color_substract(t_color a, t_color b);
t_color	color_multiply(t_color a, double multiplier);
t_color	color_divide(t_color a, double divisor);

int		map_assign_position(t_object *obj, char *s);
int		map_assign_color(t_object *obj, char *s);
int		map_assign_normalized(t_object *obj, char *s);
int		map_assign_ratio(t_object *obj, char *s);
int		map_assign_view(t_object *obj, char *s);
int		map_assign_diam_height(t_object *obj, char *s, char type);

void	map_set_defalt(t_object *obj);
int		map_set_ambient(t_object *obj, char *s);
int		map_set_camera(t_object *obj, char *s);
int		map_set_light(t_object *obj, char *s);
int		map_set_sphere(t_object *obj, char *s);
int		map_set_plane(t_object *obj, char *s);
int		map_set_cylinder(t_object *obj, char *s);

t_object	*init_obj(t_object **obj);
void	map_clear(t_main *data);
void	standardize_columns(char **addr, char *str);
void	print_obj(t_object *obj); // will be removed later

void	map_read(t_main *data, char *path);

double	hit_sphere(t_object sp, t_ray r);
double	hit_plane(t_object pl, t_ray r);
double	hit_cylinder(t_object cy, t_ray r);

double	hit_object(t_object *obj, t_ray ray);
double	solve_quadratic_minus(double a, double b, double c);
double	solve_quadratic_plus(double a, double b, double c);

#endif
