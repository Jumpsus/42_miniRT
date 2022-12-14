#include "mini_rt.h"

t_object	*init_obj(t_object **obj)
{
	if (!*obj)
	{
		*obj = malloc(sizeof(**obj));
		map_set_defalt(*obj);
		return (*obj);
	}
	return (init_obj(&(*obj)->next));
}

void	map_clear(t_main *data)
{
	t_object	*cur;
	t_object	*next;

	cur = data->obj;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

static void	drop_front_space(char *str) {
	int	pos;
	int	len;

	pos = -1;
	while (str[++pos])
		if (!ft_isspace(str[pos]))
			break ;
	len = ft_strlen(str + pos);
	ft_memmove(str, str + pos, len);
	str[len] = 0;
}

static void	drop_comma_space(char *str) {
	int	pos;

	pos = 0;
	while (str[++pos])
    {
        if (str[pos - 1] == ',' && ft_isspace(str[pos]))
            drop_front_space(str + pos--);
        else if (str[pos] == ',' && ft_isspace(str[pos - 1]))
            drop_front_space(str + --pos);
    }
}

void	standardize_columns(char **addr, char *str) {
	int	pos;

	drop_front_space(str); // removes spaces in front
	pos = -1;
	while (str[++pos])
		if (ft_isspace(str[pos]))
			break ;
	if (str[pos]) { // leave a space to seperate columns
		str[pos] = ' ';
		return (standardize_columns(addr, str + pos + 1));
	}
    drop_comma_space(*addr); // removes spaces before and after comma
}

/* will be removed later */
void	print_obj(t_object *obj)
{
	printf("id	   %d\n", obj->id);
	printf("pos	   %f,%f,%f\n", obj->pos.x, obj->pos.y, obj->pos.z);
	printf("color  %d,%d,%d\n", obj->color.r, obj->color.g, obj->color.b);
	printf("norm   %f,%f,%f\n", obj->norm.x, obj->norm.y, obj->norm.z);
	printf("ratio  %f\n", obj->ratio);
	printf("fov    %f\n", obj->fov);
	printf("diam   %f\n", obj->diam);
	printf("height %f\n", obj->height);
}
