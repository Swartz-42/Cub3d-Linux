/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:20:44 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 13:45:41 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*des;
	const unsigned char		*srt;
	size_t					i;
	int						compt;

	if (src == 0 && dest == 0)
		return (0);
	des = dest;
	srt = src;
	compt = 0;
	i = 0;
	while (i < n)
	{
		*(des + i) = *(srt + i);
		i++;
		if (*(srt + i) == (unsigned char)c && i < n)
		{
			*(des + i) = *(srt + i);
			compt = 1;
			break ;
		}
	}
	if (compt == 0)
		return (0);
	return (dest + i + 1);
}
