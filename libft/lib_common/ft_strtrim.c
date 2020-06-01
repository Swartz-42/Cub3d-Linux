/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:01:23 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 11:29:02 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

int			test_car(const char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_zero(char *str)
{
	if ((str = wrmalloc(1)) == 0)
		return (0);
	str[0] = 0;
	return (str);
}

int			ft_norminette(const char *s1, int i)
{
	while (s1[i + 1])
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (test_car(s1[i], set) && s1[i])
		i++;
	str = 0;
	if (s1[i] == 0)
		return (ft_zero(str));
	start = i;
	i = ft_norminette(s1, i);
	while (test_car(s1[i], set))
		i--;
	end = i;
	if ((str = wrmalloc(end - start + 2)) == 0)
		return (0);
	i = -1;
	while ((i++ + start) < end)
		str[i] = s1[start + i];
	str[i] = 0;
	return (str);
}
