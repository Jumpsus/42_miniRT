/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2d_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:35:55 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/13 11:36:02 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_v2.h"

char	**add_to_2d(char ***old_arr, char *mem, int idx)
{
	char	**new_arr;
	int		i;
	int		j;

	if (!*old_arr)
		return (0);
	if (idx >= size_2d(*old_arr))
		idx = size_2d(*old_arr);
	new_arr = malloc((size_2d(*old_arr) + 2) * sizeof(*new_arr));
	i = 0;
	j = 0;
	while ((*old_arr)[i])
	{
		if (i == idx)
			j++;
		new_arr[j++] = ft_strdup((*old_arr)[i++]);
	}
	new_arr[idx] = mem;
	new_arr[i + 1] = 0;
	free_2d(*old_arr);
	*old_arr = new_arr;
	return (*old_arr);
}

char	**rm_from_2d(char ***old_arr, int idx)
{
	char	**new_arr;
	int		i;
	int		j;

	if (!*old_arr)
		return (0);
	if (idx >= size_2d(*old_arr))
		return (*old_arr);
	new_arr = malloc(size_2d(*old_arr) * sizeof(*new_arr));
	i = 0;
	j = 0;
	while ((*old_arr)[i])
	{
		if (i != idx)
			new_arr[j++] = ft_strdup((*old_arr)[i]);
		i++;
	}
	new_arr[j] = 0;
	free_2d(*old_arr);
	*old_arr = new_arr;
	return (*old_arr);
}
