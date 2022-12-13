#include "mini_rt.h"

static int	open_map(char *path)
{
	int		fd;
	char	*s;

	fd = open(path, O_RDONLY);
	if (fd < 0) {
		perror("Error\n");
		return (fd);
	}
	s = ft_strchr(path, '.');
	if (s)
		if (ft_strcmp(s, ".rt") == 0)
			return (fd);
	ft_putstr_fd("Error\nfile must ending with \
		the .rt extension\n", STDERR_FILENO);
	return (-1);
}

static void	left_a_space(char *str) {
	int	pos;
	int	len;

	pos = -1;
	while (str[++pos])
		if (!ft_isspace(str[pos]))
			break ;
	len = ft_strlen(str + pos);
	ft_memmove(str, str + pos, len);
	str[len] = 0;
	pos = -1;
	while (str[++pos])
		if (ft_isspace(str[pos]))
			break ;
	if (str[pos]) {
		str[pos] = ' ';
		left_a_space(str + pos + 1);
	}
}

static int	set_obj_var(t_main *data, char *s)
{
	t_object	*obj;
	int			ret;
	int			pos;

	ret = -1;
	pos = pos_in_str(s, ' ');
	if (pos > 0)
	{
		if (ft_strncmp(s, "A", pos) == 0)
			ret = set_ambient(&data->ambient, s + pos + 1);
		else if (ft_strncmp(s, "C", pos) == 0)
			ret = set_camera(&data->camera, s + pos + 1);
		else if (ft_strncmp(s, "L", pos) == 0)
			ret = set_light(&data->light, s + pos + 1);
		else if (ft_strncmp(s, "sp", pos) == 0)
			ret = SPHERE;
		else if (ft_strncmp(s, "pl", pos) == 0)
			ret = PLANE;
		else if (ft_strncmp(s, "cy", pos) == 0)
			ret = CYLINDER;
		else
			ft_putstr_fd("Error\ninvalid type of element\n", STDERR_FILENO);
	}
	if (ret == SPHERE || ret == PLANE || ret == CYLINDER)
	{
		obj = get_last_obj(&data->obj);
		obj->id = ret;
		set_other(obj, s);
	}
	return (ret);
}

void	read_map(t_main *data, char *path)
{
	char	*line;
	int		fd;

	fd = open_map(path);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_isspace_str(line))
		{
			left_a_space(line);
			if (set_obj_var(data, line) < 0)
				exit(EXIT_FAILURE);
		}
		free(line);
	}
}
