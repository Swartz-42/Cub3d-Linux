#include "../includes/cub3d.h"

int		ft_exit(t_window *win)
{
	if (win)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
	return (0);
}

int		ft_release(int key, t_cub3d *cub3d)
{
	if (key == W)
		cub3d->player.frontward = FALSE;
	if (key == S)
		cub3d->player.backward = FALSE;
	if (key == A)
		cub3d->player.leftward = FALSE;
	if (key == D)
		cub3d->player.rightward = FALSE;
	return (0);
}

int		ft_parse_key(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		ft_exit(&cub3d->win);
	if (key == W)
		cub3d->player.frontward = TRUE;
	if (key == S)
		cub3d->player.backward = TRUE;
	if (key == A)
		cub3d->player.leftward = TRUE;
	if (key == D)
		cub3d->player.rightward = TRUE;
	if (key == FD)
	{
		cub3d->config.POV -= 0.05;
		(cub3d->config.POV < 0) ? cub3d->config.POV = 2 * M_PI : 0;
	}
	else if (key == FG)
	{
		cub3d->config.POV += 0.05;
		(cub3d->config.POV > 2 * M_PI) ? cub3d->config.POV = 0 : 0;
	}
	mlx_clear_window(cub3d->win.mlx_ptr, cub3d->win.win_ptr);
	display_game(cub3d);
	return (0);
}
