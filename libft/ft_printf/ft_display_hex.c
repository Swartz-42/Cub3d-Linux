/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:14 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/04 14:49:21 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_conversion(t_tab *tpf, int argsize)
{
	if (tpf->fprecision == FALSE && tpf->width > argsize && tpf->fzero == TRUE)
		tpf->nbzero = tpf->width - argsize;
	else if (tpf->width > 0)
		tpf->nbspace = tpf->width - argsize;
	(tpf->nbspace < 0) ? tpf->nbspace = 0 : 0;
	(tpf->nbzero < 0) ? tpf->nbzero = 0 : 0;
	if (tpf->fprecision == TRUE)
	{
		if (tpf->valprec > argsize)
		{
			if (tpf->width > tpf->valprec)
				tpf->nbspace = tpf->width - tpf->valprec;
			else
				tpf->nbspace -= tpf->nbzero;
			tpf->nbzero = tpf->valprec - argsize;
		}
		if (tpf->nbspace < 0)
			tpf->nbspace = 0;
		if (tpf->valprec >= tpf->width)
			tpf->nbspace = 0;
		else if (tpf->valprec <= argsize)
			tpf->nbzero = 0;
		if (tpf->width > argsize + tpf->nbzero)
			tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
	}
}

int			ft_display_hex(char text, t_tab *tpf)
{
	int		argsize;
	long	val;
	char	*base;

	val = va_arg(tpf->ap, long);
	argsize = ft_base_ld(val, BASE16LC);
	base = (text == 'x') ? BASE16LC : BASE16UC;
	if (val == 0 && tpf->fprecision == TRUE && tpf->valprec == 0)
	{
		argsize = 0;
		if (tpf->width > 0)
			ft_putnchar_fd(' ', tpf->width, 1);
		tpf->nbspace = tpf->width;
		tpf->nbzero = 0;
	}
	else
	{
		ft_conversion(tpf, argsize);
		ft_display_x(tpf, val, base);
	}
	tpf->length += argsize + tpf->nbzero + tpf->nbspace;
	return (tpf->length);
}
