/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 09:33:14 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 09:45:38 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*strcpy;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (start >= i)
	{
		if ((strcpy = wrmalloc(1)) == 0)
			return (0);
		strcpy[0] = 0;
		return (strcpy);
	}
	if ((strcpy = wrmalloc(len + 1)) == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		strcpy[i] = s[start + i];
		i++;
	}
	strcpy[i] = 0;
	return (strcpy);
}
