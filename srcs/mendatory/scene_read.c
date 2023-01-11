#include "mini_rt.h"

static int	scene_open(char *path)
{
	int		fd;
	char	*s;

	fd = open(path, O_RDONLY);
	if (fd < 0) {
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	s = ft_strchr(path, '.');
	if (s)
		if (ft_strcmp(s, ".rt") == 0)
			return (fd);
	ft_putendl_fd("Error\nFile must ending with \
the .rt extension", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	scene_set(t_main *data, char *s)
{
	int			ret;
	int			pos;

	ret = 0;
	pos = pos_in_str(s, ' ');
	if (pos > 0)
	{
		if (ft_strncmp(s, "A", pos) == 0)
			ret = scene_set_ambient(&data->ambient, s + pos + 1);
		else if (ft_strncmp(s, "C", pos) == 0)
			ret = scene_set_camera(&data->camera, s + pos + 1);
		else if (ft_strncmp(s, "L", pos) == 0)
			ret = scene_set_light(&data->light, s + pos + 1);
		else if (ft_strncmp(s, "sp", pos) == 0)
			ret = scene_set_sphere(init_obj(&data->obj), s + pos + 1);
		else if (ft_strncmp(s, "pl", pos) == 0)
			ret = scene_set_plane(init_obj(&data->obj), s + pos + 1);
		else if (ft_strncmp(s, "cy", pos) == 0)
			ret = scene_set_cylinder(init_obj(&data->obj), s + pos + 1);
		else
			ft_putendl_fd("Error\nInvalid type of element", STDERR_FILENO);
	}
	return (ret);
}

void	scene_read(t_main *data, char *path)
{
	char	*line;
	int		fd;

	fd = scene_open(path);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_isspace_str(line))
		{
			standardize_columns(&line, line);
			if (!scene_set(data, line))
			{
				free(line);
				scene_clear(data);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
	}
}
