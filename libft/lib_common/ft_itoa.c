/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:14:53 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 11:28:51 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../include/libft.h"

static char		*ft_zero(void)
{
	char	*str;

	if ((str = wrmalloc(2)) == 0)
		return (0);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char			*ft_insert(long n2, char *str, int i, int sign)
{
	n2 = (n2 < 0) ? -n2 : n2;
	str[i + sign] = 0;
	i--;
	while (i >= 0)
	{
		str[i + sign] = n2 % 10 + '0';
		n2 = n2 / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	long			n2;
	int				sign;

	if (n == 0)
		return (ft_zero());
	i = 0;
	n2 = (long)n;
	sign = (n2 < 0) ? 1 : 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	if ((str = wrmalloc(i + 1 + sign)) == 0)
		return (0);
	str[0] = (n2 < 0) ? '-' : 0;
	return (ft_insert(n2, str, i, sign));
}
