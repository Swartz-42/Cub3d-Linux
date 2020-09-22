#include "../includes/cub3d.h"

static int	gest_error_arg(int ac, char **av)
{
	int fd;

	if (ac != 2 || !av[1])
	{
		ft_printf("Error\nInvalid argument\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		ft_printf("Error\nInvalid file\n");
		close(fd);
		return (0);
	}
	return (fd);
}

static void	set_pov(t_cub3d cub3d)
{
	if (cub3d.config.map_ok[(int)cub3d.player.fposy / BLOCK_SIZE][(int)cub3d.player.fposx / BLOCK_SIZE] == 'E')
		cub3d.config.POV = 2 * M_PI;
	else if (cub3d.config.map_ok[(int)cub3d.player.fposy / BLOCK_SIZE][(int)cub3d.player.fposx / BLOCK_SIZE] == 'N')
		cub3d.config.POV = M_PI / 2;
	else if (cub3d.config.map_ok[(int)cub3d.player.fposy / BLOCK_SIZE][(int)cub3d.player.fposx / BLOCK_SIZE] == 'W')
		cub3d.config.POV = M_PI;
	else
		cub3d.config.POV = 3 * M_PI_2;
}

int			main(int ac, char **av)
{
	t_cub3d		cub3d;
	char		*line;
	int			fd;
	int			i;

	i = 1;
	line = NULL;
	if (!(fd = gest_error_arg(ac, av)))
		return (-1);
	ft_init_config(&cub3d.config);
	while (i > 0)
		i = ft_read_line(fd, line, &cub3d);
	close(fd);
	if (i == -1)
		return (-1);
	if (!(cub3d.config.map_ok = ft_parse_map(&cub3d)))
		return (-1);
	set_pov(cub3d);
	while (cub3d.config.map_ok[cub3d.config.y_max + 1])
	{
		while (cub3d.config.map_ok[cub3d.config.y_max][cub3d.config.x_max] != '\n')
			printf("%c",cub3d.config.map_ok[cub3d.config.y_max][cub3d.config.x_max++]);
		cub3d.config.x_max = 0;
		cub3d.config.y_max++;
		printf("\n");
	}
	while (cub3d.config.map_ok[cub3d.config.y_max][cub3d.config.x_max] != '\n')
		printf("%c",cub3d.config.map_ok[cub3d.config.y_max][cub3d.config.x_max++]);
	printf("\n");
	if (window(cub3d))
		return (-1);
	return (0);
}
