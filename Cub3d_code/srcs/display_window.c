/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:09:41 by aducas            #+#    #+#             */
/*   Updated: 2020/03/10 12:10:29 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		window(t_cub3d cub3d)
{
	if (!(cub3d.win.mlx_ptr = mlx_init()))
	{
		ft_printf("Error\nminilibx initialisation failed\n");
		return (1);
	}
	cub3d.win.win_ptr = mlx_new_window(cub3d.win.mlx_ptr, cub3d.config.x,
		cub3d.config.y, "Cub3d.exe");
	if (cub3d.win.win_ptr == NULL)
	{
		ft_printf("Error\nCould not create cub3d window\n");
		return (1);
	}
	mlx_hook(cub3d.win.win_ptr, 02, 1L << 0, ft_parse_key, &cub3d);
	mlx_hook(cub3d.win.win_ptr, 03, 1L << 1, ft_release, &cub3d);
	mlx_hook(cub3d.win.win_ptr, 33, 1L << 17, ft_exit, 0);
	mlx_loop(cub3d.win.mlx_ptr);
	return (0);
}
