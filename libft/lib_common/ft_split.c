/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:44:27 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/10 13:20:41 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "../include/libft.h"

static char		**ft_zero(char **str)
{
	if ((str = wrmalloc(sizeof(char *))) == 0)
		return (0);
	str[0] = 0;
	return (str);
}

static char		*ft_add(char *str, const char *s, int start, int end)
{
	int	i;

	i = 0;
	while (start + i <= end)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static	void	free_all(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		wrfree(str[i]);
		i++;
	}
	wrfree(str);
}

char			**ft_complete(char **str, char const *s, char c, int compt)
{
	int	i;
	int j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	while (i < compt)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		end = j - 1;
		if ((str[i] = wrmalloc(end - start + 2)) == 0)
		{
			free_all(str);
			return (0);
		}
		ft_add(str[i], s, start, end);
		i++;
	}
	str[compt] = 0;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		compt;
	int		i;
	char	**str;

	compt = 0;
	i = 0;
	str = 0;
	if (s == 0 || s[0] == 0)
		return (ft_zero(str));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			compt++;
		while (s[i] && s[i] != c)
			i++;
	}
	if ((str = ft_calloc(sizeof(char *) * (compt + 1), 1)) == 0)
		return (0);
	return (ft_complete(str, s, c, compt));
}
