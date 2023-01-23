/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pratanac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:17:45 by pratanac          #+#    #+#             */
/*   Updated: 2023/01/12 21:17:50 by pratanac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

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

# ifdef __linux__

#  define K_ESC		65307
#  define K_UP		65362
#  define K_LEFT	65361
#  define K_DOWN	65364
#  define K_RIGHT	65363
#  define K_W		119
#  define K_A		97
#  define K_S		115
#  define K_D		100
#  define K_R		114
#  define K_H		104
#  define K_Z		122
#  define K_Y		121
#  define K_X		120
#  define K_LESS	44
#  define K_MORE	46

# else

#  define K_ESC		53
#  define K_UP		126
#  define K_LEFT	123
#  define K_DOWN	125
#  define K_RIGHT	124
#  define K_W		13
#  define K_A		0
#  define K_S		1
#  define K_D		2
#  define K_R		15
#  define K_H		4
#  define K_Z		6
#  define K_Y		16
#  define K_X		7
#  define K_LESS	43
#  define K_MORE	47

# endif

# define M_UP		4
# define M_LEFT		1
# define M_DOWN		5
# define M_RIGHT	3

#endif
