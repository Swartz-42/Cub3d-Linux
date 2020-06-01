/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:45:10 by aducas            #+#    #+#             */
/*   Updated: 2020/03/09 12:27:54 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rgb_ceiling(t_config *config, char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	config->r_ceiling = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	config->g_ceiling = ft_atoi(line + ++i);
	while (ft_isdigit(line[i]))
		i++;
	config->b_ceiling = ft_atoi(line + ++i);
}

void	ft_rgb_floor(t_config *config, char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	config->r_floor = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	config->g_floor = ft_atoi(line + ++i);
	while (ft_isdigit(line[i]))
		i++;
	config->b_floor = ft_atoi(line + ++i);
}

void	ft_rgb(char *line, t_config *config)
{
	if (line[0] == 'C')
		ft_rgb_ceiling(config, line);
	else
		ft_rgb_floor(config, line);
}
