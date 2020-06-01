/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:13:31 by gbendjaf          #+#    #+#             */
/*   Updated: 2020/03/04 14:50:18 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_zero(t_tab *tpf, int argsize)
{
	argsize = 0;
	if (tpf->width > 0)
		ft_putnchar_fd(' ', tpf->width, 1);
	tpf->nbspace = tpf->width;
	tpf->nbzero = 0;
	return (argsize);
}

static void	ft_display_uint(int val, int argsize, t_tab *tpf)
{
	if (tpf->fminus == TRUE)
	{
		if (tpf->fprecision == TRUE)
			ft_precision_ui(tpf, val, argsize);
		else
			ft_display_ui(tpf, val);
	}
	else if (tpf->fzero == TRUE)
	{
		if (tpf->fprecision == TRUE)
			ft_precision_ui(tpf, val, argsize);
		else
			ft_display_ui(tpf, val);
	}
	else
	{
		if (tpf->fprecision == TRUE)
			ft_precision_ui(tpf, val, argsize);
		else
			ft_display_ui(tpf, val);
	}
}

int			ft_display_u_int(t_tab *tpf)
{
	int		argsize;
	int		val;

	val = va_arg(tpf->ap, unsigned int);
	argsize = ft_base_ui(val, BASE10);
	if (tpf->fprecision == FALSE && tpf->width > argsize && tpf->fzero == TRUE)
		tpf->nbzero = tpf->width - argsize;
	else if (tpf->width > 0)
		tpf->nbspace = tpf->width - argsize;
	(tpf->nbspace < 0) ? tpf->nbspace = 0 : 0;
	(tpf->nbzero < 0) ? tpf->nbzero = 0 : 0;
	if (tpf->valprec == 0 && val == 0 && tpf->fprecision == TRUE)
		argsize = ft_zero(tpf, argsize);
	else
		ft_display_uint(val, argsize, tpf);
	tpf->length += argsize + tpf->nbzero + tpf->nbspace;
	return (tpf->length);
}
