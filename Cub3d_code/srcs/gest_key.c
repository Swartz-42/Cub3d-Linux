/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:11:10 by aducas            #+#    #+#             */
/*   Updated: 2020/03/10 13:53:48 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	/*if (key == W || key == S)
		player->posx = 0;
	if (key == A || key == D)
		player->posy = 0;*/
}

int		ft_release(int key, t_cub3d *cub3d)
{
	if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_release_mouv(key, &cub3d->player);
	return (0);
}

void	ft_mouv(int key, t_player *player)
{
	if (key == W && player->posx != 1)
		player->posx += 1;
	else if (key == S && player->posx != -1)
		player->posx += -1;
	if (key == A && player->posy != -1)
		player->posy += -1;
	else if (key == D && player->posy != 1)
		player->posy += 1;
	ft_printf("posx: %d posy: %d\n", player->posx, player->posy);
}

int		ft_parse_key(int key, t_cub3d *cub3d)
{
	int			width;
	int			height;
	static int	flag = 0;

	if (key == ESC)
		ft_exit(&cub3d->win);
	else if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_mouv(key, &cub3d->player);
	else if (key == MAJ)
	{
		if (!flag)
		{
			cub3d->win.img = mlx_xpm_file_to_image(cub3d->win.mlx_ptr,
				cub3d->config.textno, &width, &height);
			mlx_put_image_to_window(cub3d->win.mlx_ptr,
				cub3d->win.win_ptr, cub3d->win.img, 0, 0);
		}
		else
			mlx_clear_window(cub3d->win.mlx_ptr, cub3d->win.win_ptr);
		flag = !flag;
	}
	return (0);
}
