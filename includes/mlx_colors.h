/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:49:59 by astefans          #+#    #+#             */
/*   Updated: 2025/01/04 13:03:23 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLORS_H
# define MLX_COLORS_H

// 'Encodes' four individual bytes into an int.
int	get_argb(int r, int g, int b, int a);

// Get the red channel.
int	get_r(int rgba);

// Get the green channel.
int	get_g(int rgba);

// Get the blue channel.
int	get_b(int rgba);

// Get the alpha channel.
int	get_a(int rgba);

#endif