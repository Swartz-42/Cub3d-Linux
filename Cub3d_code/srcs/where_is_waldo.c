/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_waldo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:30:04 by aducas            #+#    #+#             */
/*   Updated: 2020/06/14 11:14:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		chr_player(char **map_ok, int y, int x)
{
	while (map_ok[y][++x] != '\0')
	{
		if (ft_strchr("NSEW", map_ok[y][x]))
		{
			ft_printf("Error\nMore than one player found");
			return (1);
		}
	}
	while (map_ok[++y] != '\0')
	{
		if (ft_strchrstr(map_ok[y], "NSEW"))
		{
			ft_printf("Error\nMore than one player found");
			return (1);
		}
	}
	return (0);
}

int		find_player(char **map_ok, t_cub3d *cub3d)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while ((x = ft_strchrstr(map_ok[y], "NSEW")) == 0
<<<<<<< HEAD
		&& map_ok[y] != '\0')
=======
		&& map_ok[y + 1] != '\0')
>>>>>>> fb8175628eb35a9aed63fce8aeb43b8e62db1250
		y++;
	if (!x)
	{
		ft_printf("Error\nNo player found");
		return (1);
	}
	else
	{
		cub3d->player.posy = y;
		cub3d->player.posx = x;
	}
	if (chr_player(map_ok, y, x))
		return (1);
	return (0);
}