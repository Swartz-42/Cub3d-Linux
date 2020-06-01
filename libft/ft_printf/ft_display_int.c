/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:33:05 by aducas            #+#    #+#             */
/*   Updated: 2020/03/04 14:49:26 by aducas           ###   ########lyon.fr   */
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

static void	ft_display_pos_int(int val, int argsize, t_tab *tpf)
{
	if (tpf->fminus == TRUE)
	{
		if (tpf->fprecision == TRUE)
			ft_precision_pos(tpf, val, argsize);
		else
			ft_display(tpf, val, 0);
	}
	else if (tpf->fzero == TRUE)
	{
		if (tpf->fprecision == TRUE)
			ft_precision_pos(tpf, val, argsize);
		else
			ft_display(tpf, val, 0);
	}
	else
	{
		if (tpf->fprecision == TRUE)
			ft_precision_pos(tpf, val, argsize);
		else
			ft_display(tpf, val, 0);
	}
}

static void	ft_display_neg_int(int val, int argsize, t_tab *tpf)
{
	if (tpf->fminus == TRUE)
	{
		if (tpf->fprecision == TRUE)
			ft_precision_neg(tpf, argsize);
		ft_display(tpf, val, 1);
	}
	else if (tpf->fzero == TRUE)
	{
		if (tpf->fprecision == TRUE)
			ft_precision_neg(tpf, argsize);
		ft_display(tpf, val, 1);
	}
	else
	{
		if (tpf->fprecision == TRUE)
			ft_precision_neg(tpf, argsize);
		ft_display(tpf, val, 1);
	}
}

int			ft_display_int(t_tab *tpf)
{
	int		argsize;
	int		val;

	val = va_arg(tpf->ap, int);
	argsize = ft_base_ld(val, BASE10);
	(val < 0) ? argsize++ : 0;
	if (tpf->fprecision == FALSE && tpf->width > argsize && tpf->fzero == TRUE)
		tpf->nbzero = tpf->width - argsize;
	else if (tpf->width > 0)
		tpf->nbspace = tpf->width - argsize;
	(tpf->nbspace < 0) ? tpf->nbspace = 0 : 0;
	(tpf->nbzero < 0) ? tpf->nbzero = 0 : 0;
	if (val < 0)
		ft_display_neg_int(val, argsize, tpf);
	else if (tpf->valprec == 0 && val == 0 && tpf->fprecision == TRUE)
		argsize = ft_zero(tpf, argsize);
	else
		ft_display_pos_int(val, argsize, tpf);
	tpf->length += argsize + tpf->nbzero + tpf->nbspace;
	return (tpf->length);
}
