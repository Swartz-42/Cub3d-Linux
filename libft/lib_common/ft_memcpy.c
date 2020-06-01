/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memcpy.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:56:05 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 12:38:41 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*des;
	const unsigned char		*srt;
	size_t					i;

	if (src == 0 && dest == 0)
		return (0);
	des = dest;
	srt = src;
	i = 0;
	while (i < n)
	{
		*(des + i) = *(srt + i);
		i++;
	}
	return (dest);
}
