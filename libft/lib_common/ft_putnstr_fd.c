/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:37:42 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:37:43 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnstr_fd(char *str, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
