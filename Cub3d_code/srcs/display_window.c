#include "../includes/cub3d.h"

void minimap(t_cub3d cub3d)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int a = 0;
	int w = 0;
	int v = 0;
	int taille_cube = 15;

	while(cub3d.config.map_ok[y])
	{
		while(cub3d.config.map_ok[y][x] != '\n')
		{
			while (a < taille_cube)
			{
				while (i < taille_cube)
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
			x++;
			i = 0;
			a = 0;
			v = v + taille_cube;
		}
		v = 0;
		w = w + taille_cube;
		x = 0;
		y++;
	}
}

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
	minimap(cub3d);
	ft_printf("fini");
	mlx_loop(cub3d.win.mlx_ptr);
	return (0);
}
