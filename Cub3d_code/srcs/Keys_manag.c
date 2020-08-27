#include "../includes/cub3d.h"

int		ft_exit(t_window *win)
{
	if (win)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit(0);
	return (0);
}

void	ft_release_mouv(int key, t_player *player)
{
	if (key == W || key == S)
		player->vitx = 0;
	if (key == A || key == D)
		player->vity = 0;
}

int		ft_release(int key, t_cub3d *cub3d)
{
	if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_release_mouv(key, &cub3d->player);
	return (0);
}

void	ft_mouv_player(t_config *config, t_player *player)
{
	config->map_ok[player->posy][player->posx] = '0';
	player->posx = player->posx + player->vitx;
	player->posy = player->posy + player->vity;
	config->map_ok[player->posy][player->posx] = 'N';
}

void	ft_mouv(int key, t_player *player, t_config *config)
{
	if (key == W && player->vity > -1)
		player->vity = -1;
	else if (key == S && player->vity < 1)
		player->vity = 1;
	if (key == A && player->vitx > -1)
		player->vitx = -1;
	else if (key == D && player->vitx < 1)
		player->vitx = 1;
	if (config->map_ok[player->posy + player->vity][player->posx + player->vitx] == '1')
	{
		player->vity = 0;
		player->vitx = 0;
	}
	ft_mouv_player(config, player);
	printf("vitx: %d vity: %d\nposx: %d posy: %d\n", player->vitx, player->vity, player->posx, player->posy);
}

void ft_esteregg(t_cub3d *cub3d)
{
	static int	flag = 0;
	int			width;
	int			height;

	if (!flag)
	{
		cub3d->win.img = mlx_xpm_file_to_image(cub3d->win.mlx_ptr,
			cub3d->config.textno, &width, &height);
		mlx_clear_window(cub3d->win.mlx_ptr, cub3d->win.win_ptr);
		mlx_put_image_to_window(cub3d->win.mlx_ptr,
			cub3d->win.win_ptr, cub3d->win.img, 0, 0);
	}
	else
	{
		mlx_clear_window(cub3d->win.mlx_ptr, cub3d->win.win_ptr);
		minimap(*cub3d);
	}
	flag = !flag;
}

int		ft_parse_key(int key, t_cub3d *cub3d)
{
	if (key == ESC)
		ft_exit(&cub3d->win);
	else if ((key == W) || (key == A) || (key == S) || (key == D))
	{
		ft_mouv(key, &cub3d->player, &cub3d->config);
		mlx_clear_window(cub3d->win.mlx_ptr, cub3d->win.win_ptr);
		minimap(*cub3d);
	}
	else if (key == MAJ)
		ft_esteregg(cub3d);
	return (0);
}
