/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:03:48 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/22 00:05:06 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx/mlx.h"

/*	DEFINES	*/

# define WIDTH 800
# define HEIGHT 600

/*	STUCTS	*/

typedef struct s_data	t_data;
typedef struct s_mlx	t_mlx;

typedef struct s_data
{
	t_mlx	*mlx;
}				t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

/*	FUNCTIONS	*/

/*	window_management	*/
// open_close.c
void	open_window(t_mlx *mlx);
int		close_window(t_mlx *mlx);

/*	keyboard-events	*/
// keyboard_input.c
int		key_press(int keycode, t_mlx *mlx);
void	register_events(t_mlx *mlx);

#endif