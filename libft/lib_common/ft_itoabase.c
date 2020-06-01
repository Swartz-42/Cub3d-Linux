/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:34:50 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:34:51 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_swap(char *str)
{
	int		i;
	int		end;
	char	tmp;

	i = 0;
	end = ft_strlen(str) - 1;
	while (i < end)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		i++;
		end--;
	}
	return (str);
}

static int	ft_length(long int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoabase(long int n, char *charset)
{
	char	*str;
	int		i;
	int		base;

	base = ft_strlen(charset);
	i = 0;
	if (!(str = ft_calloc((ft_length(n, base) + 1), sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i++;
	}
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = charset[n % base];
		n = n / base;
		i++;
	}
	return (ft_swap(str));
}
