/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_v2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:45:10 by prrattan          #+#    #+#             */
/*   Updated: 2022/09/13 12:07:50 by prrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_V2_H
# define LIBFT_V2_H

# include <stdio.h>

# include "libft.h"

/* utils_str */
int		count_in_str(char *str, char c);
int		pos_in_str(char *str, char c);
int		ft_isspace(char c);
int		ft_isspace_str(char *s);
int		ft_strcmp(const char *s1, const char *s2);

/* utils_2d */
int		size_2d(char **arr);
void	free_2d(char **arr);
void	print_2d(char **arr, char delimeter);
char	**dup_2d(char **src_arr);
char	**add_to_2d(char ***old_arr, char *mem, int idx);
char	**rm_from_2d(char ***old_arr, int idx);

/* get_next_line */
char	*get_next_line(int fd);

double	ft_atof(const char *nptr);

#endif
