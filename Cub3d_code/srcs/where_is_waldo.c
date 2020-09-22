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

void	player_found(t_cub3d *cub3d, int y, int x)
{
	cub3d->player.fposy = (y * BLOCK_SIZE) - (BLOCK_SIZE / 2);
	cub3d->player.fposx = (x * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	cub3d->player.vit = 5;
	cub3d->player.frontward = FALSE;
	cub3d->player.backward = FALSE;
	cub3d->player.rightward = FALSE;
	cub3d->player.leftward = FALSE;
}

int		find_player(char **map_ok, t_cub3d *cub3d)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while ((x = ft_strchrstr(map_ok[y], "NSEW")) == 0
		&& map_ok[y + 1] != NULL)
		y++;
	if (!x)
	{
		ft_printf("Error\nNo player found");
		return (1);
	}
	else
		player_found(cub3d, y, x);
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