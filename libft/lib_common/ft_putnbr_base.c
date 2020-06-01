/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:37:18 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:37:19 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	if (!base || !ft_strlen(base))
		return ;
	if (nbr / ft_strlen(base))
		ft_putnbr_base(nbr / ft_strlen(base), base);
	ft_putchar_fd(base[nbr % ft_strlen(base)], 1);
}
