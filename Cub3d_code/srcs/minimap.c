#include "../includes/cub3d.h"

static void	minimap_2(t_cub3d cub3d, int y, int x, int v, int w)
{
	int	i;
	int a;

	i = 0;
	a = 0;
	while (a < (BLOCK_SIZE / 10))
	{
		while (i < (BLOCK_SIZE / 10))
		{
			if (cub3d.config.map_ok[y][x] == '1')
				mlx_pixel_put(cub3d.win.mlx_ptr, cub3d.win.win_ptr, v + i++, w + a, 255);
			else if (cub3d.config.map_ok[y][x] == '0')
				mlx_pixel_put(cub3d.win.mlx_ptr, cub3d.win.win_ptr, v + i++, w + a, 125);
			else
				i++;
		}
		i = 0;
		a++;
	}
}

void        minimap(t_cub3d cub3d)
{
	int x;
	int y;
	int w;
	int v;

	x = 0;
	y = 0;
	w = 0;
	v = 0;
	while(cub3d.config.map_ok[y])
	{
		while(cub3d.config.map_ok[y][x] != '\n')
		{
			minimap_2(cub3d, y, x++, v, w);
			v += (BLOCK_SIZE / 10);
		}
		v = 0;
		w += (BLOCK_SIZE / 10);
		x = 0;
		y++;
	}
}