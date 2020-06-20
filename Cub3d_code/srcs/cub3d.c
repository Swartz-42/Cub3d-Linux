#include "../includes/cub3d.h"

// TODO tester Verif map, affichage map, position player

int		gest_error_arg(int ac, char **av)
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

int		main(int ac, char **av)
{
	t_cub3d		cub3d;
	char		*line;
	int			fd;
	int			i;

	i = 1;
	line = NULL;
	ft_init_config(&cub3d.config);
	if (!(fd = gest_error_arg(ac, av)))
		return (-1);
	while (i > 0)
		i = ft_read_line(fd, line, &cub3d.config);
	close(fd);
	if (!(cub3d.config.map_ok = ft_parse_map(&cub3d)))
		return (-1);
	if (window(cub3d))
		return (-1);
	return (0);
}
