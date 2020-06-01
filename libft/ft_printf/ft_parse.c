/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:12:08 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/04 14:50:45 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_flags_2(int i, char *str, t_tab *tpf)
{
	while (ft_comp(str[i], "-0"))
	{
		if (str[i] == '-')
		{
			tpf->fminus = TRUE;
			tpf->fzero = FALSE;
		}
		if (str[i] == '0' && tpf->fminus == FALSE)
			tpf->fzero = TRUE;
		i++;
	}
	if (str[i] == '*')
		i = ft_wildcard(tpf, i);
	else if (ft_isdigit(str[i]))
	{
		tpf->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int	ft_flags(t_tab *tpf, char *str)
{
	int i;

	i = 0;
	i = ft_flags_2(i, str, tpf);
	if (str[i] == '.')
	{
		tpf->fprecision = TRUE;
		i++;
		if (str[i] == '*')
			i = ft_wildcard(tpf, i);
		else if (ft_isdigit(str[i]))
		{
			tpf->valprec = ft_atoi(str + i);
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	return (i);
}

int	ft_parse(t_tab *tpf, char *str)
{
	int	i;

	i = ft_flags(tpf, str);
	if (str[i] == 'c')
		ft_display_char(tpf);
	else if (str[i] == 's')
		ft_display_str(tpf);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_display_int(tpf);
	else if (str[i] == 'u')
		ft_display_u_int(tpf);
	else if (str[i] == 'x' || str[i] == 'X')
		ft_display_hex(str[i], tpf);
	else if (str[i] == '%')
		ft_display_percent(tpf);
	else if (str[i] == 'p')
		ft_display_addr(tpf);
	return (i + 1);
}
