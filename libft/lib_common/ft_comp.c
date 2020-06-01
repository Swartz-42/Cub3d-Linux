/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:32:51 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:32:52 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_comp(char text, char *charset)
{
	int	i;

	i = 0;
	if (!text || !charset)
		return (0);
	while (charset[i] != '\0')
	{
		if (text == charset[i])
			return (1);
		i++;
	}
	return (0);
}
