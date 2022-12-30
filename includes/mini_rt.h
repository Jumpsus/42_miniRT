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

# define SHININESS	100

# define AMBIENT	1
# define CAMERA		2
# define LIGHT		3
# define SPHERE		4
# define PLANE		5
# define CYLINDER	6

typedef struct s_matrix {
	int		n_row;
	int		n_col;
	double	*data;
}	t_matrix;

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

typedef struct s_hit {
	int			is_hit;
	double		t;
	t_point		hit_pos;
	t_point		hit_norm;
	t_object	*hit_obj;
}	t_hit;

typedef struct s_camera {
	t_point			eye;
	t_point			forward;			
	t_point			up;
	t_point			right;
	double			h;
	double			w;
}	t_camera;

typedef struct s_main {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_color		background;
	t_object	ambient;
	t_object	camera;
	t_object	light;
	t_object	*obj;
}	t_main;

void	rt_init(t_main *data, char *path);
int		rt_clear(t_main *data);
int		rt_key(int key, t_main *data);
int		rt_render(t_main *data);

void	camera_render(t_main *data);
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
void		rotate_object(t_object *obj, double x_rot, double y_rot, double z_rot);
t_ray		create_ray(t_point orig, t_point dir);
t_point		ray_at(t_ray x, double t);

/* color_utils */
int		rgb_to_int(t_color color);
t_color	color_add(t_color a, t_color b);
t_color	color_substract(t_color a, t_color b);
t_color	color_multiply_color(t_color a, t_color b);
t_color	color_multiply_n(t_color a, double multiplier);
t_color	color_divide(t_color a, double divisor);
t_color	color_normalize(t_color a);

/* scene_assign */
int		scene_assign_position(t_object *obj, char *s);
int		scene_assign_color(t_object *obj, char *s);
int		scene_assign_normalized(t_object *obj, char *s);
int		scene_assign_ratio(t_object *obj, char *s);
int		scene_assign_view(t_object *obj, char *s);
int		scene_assign_diam_height(t_object *obj, char *s, char type);

/* scene_set */
void	scene_set_defalt(t_object *obj);
int		scene_set_ambient(t_object *obj, char *s);
int		scene_set_camera(t_object *obj, char *s);
int		scene_set_light(t_object *obj, char *s);
int		scene_set_sphere(t_object *obj, char *s);
int		scene_set_plane(t_object *obj, char *s);
int		scene_set_cylinder(t_object *obj, char *s);

t_object	*init_obj(t_object **obj);
void	scene_clear(t_main *data);
void	standardize_columns(char **addr, char *str);
void	print_obj(t_object *obj); // will be removed later

void	scene_read(t_main *data, char *path);

/* hit */
t_hit	hit_object(t_main *data, t_ray r);
t_hit	hit_sphere(t_object *sp, t_ray r);
t_hit	hit_plane(t_object *pl, t_ray r);
t_hit	hit_cylinder(t_object *cy, t_ray r);

/* hit_utils */
double	solve_quadratic_minus(double a, double b, double c);
double	solve_quadratic_plus(double a, double b, double c);
t_hit	set_hit_property(double t, t_object *obj, t_ray r);
t_hit	select_hit(t_hit a, t_hit b);

/* trace */
t_color	trace(t_main *data, t_ray r);

t_matrix	*create_matrix(int n_row, int n_col);
void		delete_matrix(t_matrix *mtx);
double		matrix_get(t_matrix *mtx, int row, int col);
void		matrix_set(t_matrix *mtx, int row, int col, double val);
t_matrix	*matrix_multiply(t_matrix *a, t_matrix *b);
t_matrix	*get_orientation_matrix(t_point xaxis, t_point yaxis, t_point zaxis);
t_matrix	*get_translation_matrix(t_point eye);
t_matrix	*get_view_matrix(t_point xaxis, t_point yaxis, t_point zaxis, t_point eye);

#endif
