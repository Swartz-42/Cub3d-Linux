#include "../includes/cub3d.h"

void	loop(t_cub3d cub3d)
{
	//mlx_loop_hook(cub3d.win.mlx_ptr, display_game, &cub3d);
	display_game(&cub3d);
	mlx_hook(cub3d.win.win_ptr, 02, 1L << 0, ft_parse_key, &cub3d);
	mlx_hook(cub3d.win.win_ptr, 03, 1L << 1, ft_release, &cub3d);
	mlx_hook(cub3d.win.win_ptr, 33, 1L << 17, ft_exit, 0);
	mlx_loop(cub3d.win.mlx_ptr);
}

int		window(t_cub3d cub3d)
{
	if (!(cub3d.win.mlx_ptr = mlx_init()))
	{
		ft_printf("Error\nminilibx initialisation failed\n");
		return (1);
	}
	cub3d.win.win_ptr = mlx_new_window(cub3d.win.mlx_ptr, cub3d.win.x,
		cub3d.win.y, "Cub3d.exe");
	if (!cub3d.win.win_ptr)
	{
		ft_printf("Error\nCould not create cub3d window\n");
		return (1);
	}
	loop(cub3d);
	return (0);
}
