/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:35:50 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/13 11:35:52 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_v2.h"

int	size_2d(char **arr)
{
	int	size;

	size = 0;
	if (arr)
		while (arr[size])
			size++;
	return (size);
}

void	free_2d(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	print_2d(char **arr, char delimeter)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			printf("%s", arr[i]);
			if (arr[++i])
				printf("%c", delimeter);
		}
		i++;
	}
}

char	**dup_2d(char **src_arr)
{
	char	**new_arr;
	int		i;

	if (!src_arr)
		return (0);
	new_arr = malloc((size_2d(src_arr) + 1) * sizeof(*new_arr));
	i = 0;
	while (src_arr[i])
	{
		new_arr[i] = ft_strdup(src_arr[i]);
		i++;
	}
	new_arr[i] = 0;
	return (new_arr);
}
