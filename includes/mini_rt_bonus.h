#ifndef MINI_RT_BONUS_H
# define MINI_RT_BONUS_H

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
# include "vector.h"
# include "color.h"

# define WINDOW_WIDTH	1200
# define WINDOW_HEIGHT	600

# define SHININESS	100

# define AMBIENT	1
# define CAMERA		2
# define LIGHT		3
# define SPHERE		4
# define PLANE		5
# define CYLINDER	6
# define CONE		7

typedef struct s_matrix {
	int		n_row;
	int		n_col;
	double	*data;
}	t_matrix;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

/*
	id     	- for all objects
	pos    	- for all objects except ambient 
	color  	- for all objects except camera 
	norm   	- (normalized) for camera, plane and cylinder 
	ratio  	- for ambient and light 
	fov   	- for camera 
	radius 	- for sphere and cylinder 
	height 	- for cylinder 
*/
typedef struct s_object {
	int				id;
	t_point			pos;
	t_color			color;
	t_point			norm;
	double			ratio;
	double			fov;
	double			radius;
	double			height;
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
	double			aspect_ratio;
	double			fov;
	double			roll;
	double			pitch;
	double			yaw;
}	t_camera;

typedef struct s_select_object {
	t_object	*obj;
	int			mode;
}	t_select_object;

typedef struct s_main {
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_color			background;
	t_object		ambient;
	t_object		camera;
	t_object		*light;
	t_camera		use_camera;
	t_object		*obj;
	t_select_object	select_obj;
}	t_main;

void		rt_init(t_main *data, char *path);
int			rt_clear(t_main *data);
int			rt_key(int key, t_main *data);
int			rt_mouse(int key, int x, int y, t_main *data);
int			rt_render(t_main *data);

/* event */
int			rt_adjust_rots(int key, t_main *data);
int			rt_adjust_trans(int key, t_main *data);
int			rt_set_obj_mode(int key, t_main *data);
int			rt_scroll(int key, t_main *data);
int			rt_adjust_object(int key, t_main *data);

/* camera */
t_camera	create_camera(t_object camera);
t_ray		make_ray_from_pixel(t_camera *cam, int x, int y);
void		camera_render(t_main *data);
void		img_pix_put(t_img *img, int x, int y, t_color color);

/* scene_assign */
int			scene_assign_position(t_object *obj, char *s);
int			scene_assign_color(t_object *obj, char *s);
int			scene_assign_normalized(t_object *obj, char *s);
int			scene_assign_ratio(t_object *obj, char *s);
int			scene_assign_view(t_object *obj, char *s);
int			scene_assign_diam_height(t_object *obj, char *s, char type);

/* scene_set */
void		scene_set_defalt(t_object *obj);
int			scene_set_ambient(t_object *obj, char *s);
int			scene_set_camera(t_object *obj, char *s);
int			scene_set_light(t_object *obj, char *s);
int			scene_set_sphere(t_object *obj, char *s);
int			scene_set_plane(t_object *obj, char *s);
int			scene_set_cylinder(t_object *obj, char *s);
int			scene_set_cone(t_object *obj, char *s);

t_object	*init_obj(t_object **obj);
void		scene_clear(t_main *data);
void		standardize_columns(char **addr, char *str);
void		print_obj(t_object *obj); // will be removed later
void		scene_read(t_main *data, char *path);

/* hit */
t_hit		hit_object(t_main *data, t_ray r);
t_hit		hit_sphere(t_object *sp, t_ray r);
t_hit		hit_plane(t_object *pl, t_ray r);
t_hit		hit_cylinder(t_object *cy, t_ray r);
t_hit		hit_cone(t_object *co, t_ray r);

/* hit_utils */
double		solve_quadratic_minus(double a, double b, double c);
double		solve_quadratic_plus(double a, double b, double c);
t_hit		set_hit_property(double t, t_object *obj, t_ray r);
t_hit		select_hit(t_hit a, t_hit b);

/* trace */
t_color		trace(t_main *data, t_ray r);

t_matrix	*create_matrix(int n_row, int n_col);
void		delete_matrix(t_matrix *mtx);
double		matrix_get(t_matrix *mtx, int row, int col);
void		matrix_set(t_matrix *mtx, int row, int col, double val);
t_matrix	*matrix_multiply(t_matrix *a, t_matrix *b);
t_matrix	*get_orientation_matrix(t_point xaxis,
				t_point yaxis, t_point zaxis);
t_matrix	*get_translation_matrix(t_point eye);
t_matrix	*get_view_matrix(t_point xaxis, t_point yaxis,
				t_point zaxis, t_point eye);
void		rotate_object(t_object *obj, double x_rot,
				double y_rot, double z_rot);

#endif
