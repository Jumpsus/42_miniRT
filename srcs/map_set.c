#include "mini_rt.h"

void	map_set_defalt(t_object *obj)
{
	obj->id = 0;
	obj->pos = (t_point){0, 0, 0};
	obj->color = (t_color){0, 0, 0};
	obj->norm = (t_point){0, 0, 0};
	obj->ratio = 0;
	obj->fov = 0;
	obj->diam = 0;
	obj->height = 0;
	obj->next = 0;
}

int	map_set_ambient(t_object *obj, char *s)
{
	char	**inp;
	char	*err;

	err = "Error\nambient lighting must only consist of \
ambient lighting ratio and rgb colors\n";
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
		ft_putstr_fd(err, STDERR_FILENO);
	free_2d(inp);
	//print_obj(obj);
	return (obj->id);
}

int	map_set_camera(t_object *obj, char *s)
{
	char	**inp;
	char	*err;

	err = "Error\ncamera must only consist of xyz coordinates, \
3d normalized orientation vector and horizontal field of view\n";
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
		ft_putstr_fd(err, STDERR_FILENO);
	free_2d(inp);
	//print_obj(obj);
	return (obj->id);
}

int	map_set_light(t_object *obj, char *s)
{
	char	**inp;
	char	*err;

	err = "Error\nlight must only consist of xyz coordinates, \
brightness ratio and rgb colors\n";
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
		ft_putstr_fd(err, STDERR_FILENO);
	free_2d(inp);
	//print_obj(obj);
	return (obj->id);
}

int	map_set_sphere(t_object *obj, char *s)
{
	char	**inp;
	char	*err;

	err = "Error\nsphere must only consist of xyz coordinates, \
diameter and rgb colors\n";
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_diam_height(obj, inp[1], 'd'))
				if (map_assign_color(obj, inp[2]))
					obj->id = SPHERE;
	}
	else
		ft_putstr_fd(err, STDERR_FILENO);
	free_2d(inp);
	//print_obj(obj);
	return (obj->id);
}

int	map_set_plane(t_object *obj, char *s)
{
	char	**inp;
	char	*err;

	err = "Error\nplane must only consist of xyz coordinates, \
3d normalized orientation vector and rgb colors\n";
	inp = ft_split(s, ' ');
	if (size_2d(inp) == 3)
	{
		if (map_assign_position(obj, inp[0]))
			if (map_assign_normalized(obj, inp[1]))
				if (map_assign_color(obj, inp[2]))
					obj->id = PLANE;
	}
	else
		ft_putstr_fd(err, STDERR_FILENO);
	free_2d(inp);
	//print_obj(obj);
	return (obj->id);
}

int	map_set_cylinder(t_object *obj, char *s)
{
	char	**inp;
	char	*err;

	err = "Error\ncylinder must only consist of xyz coordinates, \
3d normalized orientation vector, diameter, height and rgb colors\n";
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
		ft_putstr_fd(err, STDERR_FILENO);
	free_2d(inp);
	//print_obj(obj);
	return (obj->id);
}
