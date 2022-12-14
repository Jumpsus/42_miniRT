#include "mini_rt.h"

void	map_set_defalt(t_object *obj)
{
	obj->id = 0;
	obj->pos = (t_point){0, 0, 0};
	obj->color = (t_color){0, 0, 0};
	obj->norm = (t_point){0, 0, 0};
	obj->ratio = 0;
	obj->view = 0;
	obj->diam = 0;
	obj->height = 0;
	obj->next = 0;
}

int	map_set_ambient(t_object *obj, char *s)
{
	char	**inp;

	if (obj->id == AMBIENT)
		return (0);
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 2)
	{
		if (map_assign_ratio(obj, inp[0]))
			if (map_assign_color(obj, inp[1]))
				obj->id = AMBIENT;
	}
	else
		ft_putstr_fd("Error\nambient lighting must \
contains\n", STDERR_FILENO);
	free_2d(inp);
	print_obj(obj);
	return (obj->id);
}

int	map_set_camera(t_object *obj, char *s)
{
	char	**inp;

	if (obj->id == CAMERA)
		return (0);
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_normalized(obj, inp[1]))
				if (map_assign_view(obj, inp[2]))
					obj->id = CAMERA;
	}
	else
		ft_putstr_fd("Error\ncamera must \
contains\n", STDERR_FILENO);
	free_2d(inp);
	print_obj(obj);
	return (obj->id);
}

int	map_set_light(t_object *obj, char *s)
{
	char	**inp;

	if (obj->id == LIGHT)
		return (0);
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_ratio(obj, inp[1]))
				if (map_assign_color(obj, inp[2]))
					obj->id = LIGHT;
	}
	else
		ft_putstr_fd("Error\nlight must \
contains\n", STDERR_FILENO);
	free_2d(inp);
	print_obj(obj);
	return (obj->id);
}

int	map_set_sphere(t_object *obj, char *s)
{
	char	**inp;

	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_diam_height(obj, inp[1], 'd'))
				if (map_assign_color(obj, inp[2]))
					obj->id = SPHERE;
	}
	else
		ft_putstr_fd("Error\nsphere must \
contains\n", STDERR_FILENO);
	free_2d(inp);
	print_obj(obj);
	return (obj->id);
}

int	map_set_plane(t_object *obj, char *s)
{
	char	**inp;

	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_normalized(obj, inp[1]))
				if (map_assign_color(obj, inp[2]))
					obj->id = PLANE;
	}
	else
		ft_putstr_fd("Error\nplane must \
contains\n", STDERR_FILENO);
	free_2d(inp);
	print_obj(obj);
	return (obj->id);
}

int	map_set_cylinder(t_object *obj, char *s)
{
	char	**inp;

	inp = ft_split(s, ' ');
	if (size_2d(inp) == 5)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_normalized(obj, inp[1]))
				if (map_assign_diam_height(obj, inp[2], 'd'))
					if (map_assign_diam_height(obj, inp[3], 'h'))
						if (map_assign_color(obj, inp[4]))
							obj->id = CYLINDER;
	}
	else
		ft_putstr_fd("Error\ncylinder must \
contains\n", STDERR_FILENO);
	free_2d(inp);
	print_obj(obj);
	return (obj->id);
}
