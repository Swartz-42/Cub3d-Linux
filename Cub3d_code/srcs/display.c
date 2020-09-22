#include "../includes/cub3d.h"

void	draw_floor(t_cub3d cub3d, int x)
{
	int y;

		y = (cub3d.win.y / 2);
		while (y != cub3d.win.y)
			mlx_pixel_put(cub3d.win.mlx_ptr, cub3d.win.win_ptr, x, y++, cub3d.config.rgb_floor);
}

void	draw_ceiling(t_cub3d cub3d, int x)
{
	int y;

	y = 0;
	while (y < cub3d.win.y / 2)
		mlx_pixel_put(cub3d.win.mlx_ptr, cub3d.win.win_ptr, x, y++, cub3d.config.rgb_ceiling);
}

void	display_wall(int x, float projected_wall, t_cub3d cub3d)
{
    int y;
    int color;

	color = (projected_wall > 255) ? rgb_int(0, 255, 0, 0) :
			rgb_int(0,(int)projected_wall,0,0);
    y = (cub3d.win.y / 2) - (projected_wall / 2);
    while (y < ((cub3d.win.y / 2) + (projected_wall / 2)))
        mlx_pixel_put(cub3d.win.mlx_ptr, cub3d.win.win_ptr, x, y++, color);
}

int		display_game(t_cub3d *cub3d)
{
	int	x;
	
	x = 0;
	ft_mouv(&cub3d->player, &cub3d->config);
	while (x < cub3d->win.x)
	{
		draw_ceiling(*cub3d, x);
		draw_floor(*cub3d, x);
		x++;
	}
    scan(cub3d);
	minimap(*cub3d);
	return (0);
}