#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./minilibx/mlx.h"

# define WIDTH 800
# define HEIGHT 600

typedef	struct s_data t_data;
typedef	struct s_mlx t_mlx;

typedef struct s_data
{
	t_mlx	*mlx;
}				t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

#endif