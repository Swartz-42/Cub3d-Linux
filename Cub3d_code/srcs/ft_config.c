/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:49:16 by aducas            #+#    #+#             */
/*   Updated: 2020/03/09 11:48:25 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_config(t_config *config)
{
	config->x = 0;
	config->y = 0;
	config->textno = ft_strdup("");
	config->textso = ft_strdup("");
	config->textwe = ft_strdup("");
	config->textea = ft_strdup("");
	config->sprite = ft_strdup("");
	config->r_floor = 0;
	config->g_floor = 0;
	config->b_floor = 0;
	config->r_ceiling = 0;
	config->g_ceiling = 0;
	config->b_ceiling = 0;
	config->map = ft_strdup("");
}

void	resolution(char *line, t_config *config)
{
	int i;

	i = 0;
	config->x = ft_atoi(line + 1);
	i = ft_strlen(line);
	while (!ft_isdigit(line[i]))
		i--;
	while (ft_isdigit(line[i]))
		i--;
	config->y = ft_atoi(line + i);
}

void	ft_parse3d(char *line, t_config *config)
{
	if (line[0] == 'R')
		resolution(line, config);
	else if (line[0] == 'N' && line[1] == 'O')
		config->textno = ft_strdup(line + 3);
	else if (line[0] == 'S' && line[1] == 'O')
		config->textso = ft_strdup(line + 3);
	else if (line[0] == 'W' && line[1] == 'E')
		config->textwe = ft_strdup(line + 3);
	else if (line[0] == 'E' && line[1] == 'A')
		config->textea = ft_strdup(line + 3);
	else if (line[0] == 'S')
		config->sprite = ft_strdup(line + 2);
	else if (line[0] == 'F' || line[0] == 'C')
		ft_rgb(line, config);
	else
		ft_printf("ERROR\nInvalid parameter\n");
}

int		ft_read_line(int fd, char *line, t_config *config)
{
	int ret;

	ret = get_next_line(fd, &line);
	if (ft_comp(line[0], "RNSWEFC"))
		ft_parse3d(line, config);
	else if (line[0] == '1' && line[ft_strlen(line) - 1] == '1')
		config->map = ft_strjoin(config->map, ft_strjoin(line, "\n"));
	else if ((line[0] != '1' || line[ft_strlen(line) - 1] != '1') &&
			(read(fd, line, 0) >= 1))
	{
		ft_printf("ERROR\nInvalid map\n");
		return (-1);
	}
	line = 0;
	if (ret == 0)
		return (0);
	return (1);
}
