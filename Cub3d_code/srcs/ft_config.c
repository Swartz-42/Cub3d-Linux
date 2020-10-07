#include "../includes/cub3d.h"

void	ft_init_config(t_config *config)
{
	config->textno = ft_strdup("");
	config->textso = ft_strdup("");
	config->textwe = ft_strdup("");
	config->textea = ft_strdup("");
	config->sprite = ft_strdup("");
	config->rgb_ceiling = 0;
	config->rgb_floor = 0;
	config->map = ft_strdup("");
	config->y_max = 0;
	config->x_max = 0;
}

static int	resolution(char *line, t_window *win)
{
	int i;

	i = 0;
	win->x = ft_atoi(line + 1);
	i = ft_strlen(line);
	while (!ft_isdigit(line[i]))
		i--;
	while (ft_isdigit(line[i]))
		i--;
	win->y = ft_atoi(line + i);
	if (win->x < 0 || win->y < 0)
	{
		ft_printf("Error\nSize of windows x < 0 or y < 0\n");
		return (-1);
	}
	if (win->x > 1920)
		win->x = 1920;
	if (win->y > 1080)
		win->y = 1080;
	return (0);
}

static char	*path(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '.' && i < ft_strlen(line))
		i++;
	if (i < ft_strlen(line))
		return(ft_strdup(line +i));
	else
		return("ERROR\nBad path\n");
}

int			ft_parse3d(char *line, t_cub3d *cub3d)
{
	if (line[0] == 'R')
		resolution(line, &cub3d->win);
	else if (line[0] == 'N' && line[1] == 'O')
		cub3d->config.textno = path(line);
	else if (line[0] == 'S' && line[1] == 'O')
		cub3d->config.textso = path(line);
	else if (line[0] == 'W' && line[1] == 'E')
		cub3d->config.textwe = path(line);
	else if (line[0] == 'E' && line[1] == 'A')
		cub3d->config.textea = path(line);
	else if (line[0] == 'S')
		cub3d->config.sprite = path(line);
	else if (line[0] == 'F' || line[0] == 'C')
	{
		if (ft_rgb(line, &cub3d->config) == -1)
			return (-1);
	}
	else
	{
		ft_printf("ERROR\nInvalid parameter\n");
		return (-1);
	}
	return (0);
}

int			ft_read_line(int fd, char *line, t_cub3d *cub3d)
{
	int ret;

	ret = get_next_line(fd, &line);
	if (ft_comp(line[0], "RNSWEFC"))
	{
		if (ft_parse3d(line, cub3d))
			return(-1);
	}
	else if (ft_comp('1', line))
		cub3d->config.map = ft_strjoin(cub3d->config.map, ft_strjoin(line, "\n"));
	else if (!(ft_comp('1', line)) && (read(fd, line, 0) > 0))
	{
		ft_printf("ERROR\nInvalid map\n");
		return (-1);
	}
	line = 0;
	if (ret == 0)
		return (0);
	return (1);
}
