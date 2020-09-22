#include "../includes/cub3d.h"

static int		skip(char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	return (i);
}

static int		ft_add_rgb(t_config *config, char *line)
{
	int	i;
	int r;
	int g;
	int b;

	i = skip(line, 0);
	r = ft_atoi(line + i);
	i = skip(line, i);
	g = ft_atoi(line + ++i);
	i = skip(line, i);
	b = ft_atoi(line + ++i);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		ft_printf("Error\nColors for ceiling or floor not in range [0,255]\n");
		return(-1);
	}
	return(rgb_int(0, r, g, b));
}

int     		rgb_int(unsigned char alpha, unsigned char r, unsigned char g, unsigned char b)
{
    int rgb;

    rgb = (int)alpha;
    rgb = (rgb << 8) + (int)r;
    rgb = (rgb << 8) + (int)g;
    rgb = (rgb << 8) + (int)b;
    return (rgb);
}

int				ft_rgb(char *line, t_config *config)
{
	int	rgb;

	rgb = ft_add_rgb(config, line);
	if (rgb == -1)
		return(-1);
	if (line[0] == 'C')
		config->rgb_ceiling = rgb;
	else
		config->rgb_floor = rgb;
	return(0);
}
