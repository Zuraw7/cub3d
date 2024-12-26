#include "../includes/cub3d.h"

static void	cursor_limit(t_data *data, int x, int y)
{
	if (x > data->win_width - MOUSE_EDGE_LIMIT)
	{
		x = MOUSE_EDGE_LIMIT;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	if (x < MOUSE_EDGE_LIMIT)
	{
		x = data->win_width - MOUSE_EDGE_LIMIT;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
}
//player_rotation.c do zrobienia, ale to potem
/*static int	mouse_handler(int x, int y, t_data *data)
{
	static int	previous_x = WIDTH / 2;

	cursor_limit(data, x, y);
	if (x == previous_x)
		return (0);
	else if (x < previous_x)
		data->player.has_moved += player_rotation(data, -1);
	else if (x > previous_x)
		data->player.has_moved += player_rotation(data, 1);
	previous_x = x;
	return (0);
}*/