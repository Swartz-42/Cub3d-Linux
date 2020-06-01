/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:35:24 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/10 12:21:57 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = (char *)(s + i);
		i++;
	}
	if (c == 0)
		str = (char *)(s + i);
	return (str);
}

int		ft_strchrstr(char *s, char *c)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (c[x])
		{
			if (s[i] == c[x])
				return (i);
			x++;
		}
		x = 0;
		i++;
	}
	return (0);
}
