/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:33:05 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/21 19:14:38 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_base_ld(long nbr, char *base)
{
	int i;
	int	len;

	len = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / len;
		i++;
	}
	return (i);
}

int		ft_base(unsigned long nbr, char *base)
{
	int i;
	int	len;

	len = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / len;
		i++;
	}
	return (i);
}

int		ft_base_ui(unsigned int nbr, char *base)
{
	int i;
	int	len;

	len = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / len;
		i++;
	}
	return (i);
}
