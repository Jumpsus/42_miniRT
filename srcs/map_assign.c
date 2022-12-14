#include "mini_rt.h"

static int	check_input(char *s, double start, double end, int is_int)
{
	double	n;
	int		dot;
	int		len;

	dot = 0;
	if (is_int)
		dot = 1;
	len = -1;
	if (*s == '+' || *s == '-')
		len++;
	while (s[++len])
	{
		if (!dot && s[len] == '.')
			dot = 1;
		else if (!ft_isdigit(s[len]))
			return (0);
	}
	n = ft_atof(s);
	return (n >= start && n <= end);
}

static int	check_all_input(char **inp, double start, double end, int is_int)
{
	int	size;

	size = size_2d(inp);
	while (size-- > 0)
		if (!check_input(inp[size], start, end, is_int))
			return (0);
	return (1);
}

int	map_assign_position(t_object *obj, char *s)
{
	char	**pos;
	char	*err;

	err = "Error\nx,y,z coordinates must be of \
the format \"n,n,n\" where n is a double\n";
	pos = ft_split(s, ',');
	if (size_2d(pos) == 3)
	{
		if (check_all_input(pos, -DBL_MAX, DBL_MAX, 0))
		{
			obj->pos.x = ft_atof(pos[0]);
			obj->pos.y = ft_atof(pos[1]);
			obj->pos.z = ft_atof(pos[2]);
			free_2d(pos);
			return (1);
		}
	}
	free_2d(pos);
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}

int	map_assign_color(t_object *obj, char *s)
{
	char	**color;
	char	*err;

	err = "Error\nRGB colors must be of the format \
\"n,n,n\" where n is an integer in the range [0,255]\n";
	color = ft_split(s, ',');
	if (size_2d(color) == 3)
	{
		if (check_all_input(color, 0, 255, 1))
		{
			obj->color.r = ft_atoi(color[0]);
			obj->color.g = ft_atoi(color[1]);
			obj->color.b = ft_atoi(color[2]);
			free_2d(color);
			return (1);
		}
	}
	free_2d(color);
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}

int	map_assign_normalized(t_object *obj, char *s)
{
	char	**norm;
	char	*err;

	err = "Error\n3d normalized orientation vector \
must be of the format \"n,n,n\" where n is \
a double in the range [-1,1]\n";
	norm = ft_split(s, ',');
	if (size_2d(norm) == 3)
	{
		if (check_all_input(norm, -1, 1, 0))
		{
			obj->norm.x = ft_atof(norm[0]);
			obj->norm.y = ft_atof(norm[1]);
			obj->norm.z = ft_atof(norm[2]);
			free_2d(norm);
			return (1);
		}
	}
	free_2d(norm);
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}

int	map_assign_ratio(t_object *obj, char *s)
{
	char	*err;

	err = "Error\nratio must be of the format \
\"n\" where n is a double in the range [0,1]\n";
	if (check_input(s, 0, 1, 0))
	{
		obj->ratio = ft_atof(s);
		return (1);
	}
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}

int	map_assign_view(t_object *obj, char *s)
{
	char	*err;

	err = "Error\nfield of view must be of the format \
\"n\" where n is a double in the range [0,180]\n";
	if (check_input(s, 0, 180, 0))
	{
		obj->fov = ft_atof(s);
		return (1);
	}
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}

int	map_assign_diam_height(t_object *obj, char *s, char type)
{
	char	*err;

	if (!(type == 'h' || type == 'd'))
		return (0);
	else if (type == 'h')
		err = "Error\nheight must be of the format \
\"n\" where n is a double\n";
	else if (type == 'd')
		err = "Error\ndiameter must be of the format \
\"n\" where n is a double\n";
	if (check_input(s, -DBL_MAX, DBL_MAX, 0))
	{
		if (type == 'h')
			obj->height = ft_atof(s);
		else if (type == 'd')
			obj->diam = ft_atof(s);
		return (1);
	}
	ft_putstr_fd(err, STDERR_FILENO);
	return (0);
}
