/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuraw <zuraw@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:57 by zuraw             #+#    #+#             */
/*   Updated: 2024/12/30 20:03:58 by zuraw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COLORS_H
# define MLX_COLORS_H

// 'Encodes' four individual bytes into an int.
int	get_rgba(int r, int g, int b, int a);

// Get the red channel.
int	get_r(int rgba);

// Get the green channel.
int	get_g(int rgba);

// Get the blue channel.
int	get_b(int rgba);

// Get the alpha channel.
int	get_a(int rgba);

#endif