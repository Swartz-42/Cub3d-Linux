/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:22 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/04 14:50:53 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_precision_neg(t_tab *tpf, int argsize)
{
	if (tpf->valprec >= argsize)
	{
		tpf->nbzero = (tpf->valprec - argsize) + 1;
		tpf->nbspace -= tpf->nbzero;
	}
	else
		tpf->nbzero = 0;
	if (tpf->nbspace < 0)
		tpf->nbspace = 0;
	if (tpf->width > argsize + tpf->nbzero)
		tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
}

void	ft_precision_pos(t_tab *tpf, int val, int argsize)
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
	else
	{
		ft_display(tpf, val, 0);
		return ;
	}
	if (tpf->width > argsize + tpf->nbzero)
		tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
	ft_display(tpf, val, 0);
}

void	ft_precision_ui(t_tab *tpf, int val, int argsize)
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
	else
	{
		ft_display_ui(tpf, val);
		return ;
	}
	if (tpf->width > argsize + tpf->nbzero)
		tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
	ft_display_ui(tpf, val);
}
