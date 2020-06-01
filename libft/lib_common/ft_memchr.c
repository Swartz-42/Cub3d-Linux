/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:22:28 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 13:45:41 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char			*strcpy;
	unsigned int	i;

	strcpy = (char *)str;
	i = 0;
	while (i < n)
	{
		if (strcpy[i] == c)
			return (strcpy + i);
		i++;
	}
	return (0);
}
