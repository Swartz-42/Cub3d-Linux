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
		&& map_ok[y] != '\0')
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
		cub3d->player.vitx = 0;
		cub3d->player.vity = 0;
	}
	if (chr_player(map_ok, y, x))
		return (1);
	if (map_ok[y][x + 1] == ' ' || map_ok[y][x - 1] == ' '
		|| map_ok[y + 1][x] == ' ' || map_ok[y - 1][x] == ' ')
	{
		ft_printf("Error\nSpace near player");
		return (1);
	}
	return (0);
}