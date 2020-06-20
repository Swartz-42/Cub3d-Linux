#include "../includes/cub3d.h"

int zero_verif_two(char **map_ok, int y, int x)
{
	int i;

	i = x;
	while (map_ok[y][i] != '\n' && map_ok[y][i] == '0')
		i++;
	if (map_ok[y][i] == ' ')
		return (1);
	i = y;
    while (map_ok[i][x] == '0' && i != 0)
    	i--;
    if (map_ok[i][x] == ' ')
        return (1);
	i = y;
	while (map_ok[i][x] == '0' && map_ok[i + 1])
        i++;
    if (map_ok[i][x] == ' ')
        return (1);
	return (0);
}

int zero_verif(char **map_ok)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_ok[y])
	{
		while (map_ok[y][x] != '\n')
		{
			if (map_ok[y][x] == '0')
			{
                if (zero_verif_two(map_ok, y, x))
					return (1);
				x++;
			}
			else
				x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	check_first_last_lane(char **map_ok, int y, int x)
{
	while(map_ok[y])
	{
		if (map_ok[y][0] == '0' || map_ok[y][ft_strlen(map_ok[y])] == '0')
			return (1);
		y++;
	}
	while (map_ok[0][x] != '\n')
	{
		if (map_ok[0][x] == '0' || map_ok[0][x] == '2')
			return (1);
		x++;
	}
	x = 0;
	y--;
	while (map_ok[y][x] != '\n')
	{
		if (map_ok[y][x] == '0' || map_ok[y][x] == '2')
			return (1);
		x++;
	}
	return (0);
}

int	verif_map(char **map_ok)
{
	if(check_first_last_lane(map_ok, 0, 0))
		return(1);
	if (zero_verif(map_ok))
		return (1);
	return (0);
}

char	**ft_parse_map(t_cub3d *cub3d)
{
	char	**map_ok;

	map_ok = ft_split(cub3d->config.map, '\n');
	if (find_player(map_ok, cub3d))
		return (0);
	if (verif_map(map_ok))
	{
		ft_printf("Error\nIncorrect Map");
		return (0);
	}
	return (map_ok);
}