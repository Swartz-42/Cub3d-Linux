/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:20:44 by lrobert           #+#    #+#             */
/*   Updated: 2020/03/04 14:51:00 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_wildcard_width(t_tab *tpf)
{
	tpf->width = va_arg(tpf->ap, int);
	if (tpf->width < 0)
	{
		tpf->width = -tpf->width;
		tpf->fminus = TRUE;
		tpf->fzero = FALSE;
	}
}

void	ft_wildcard_prec(t_tab *tpf)
{
	tpf->valprec = va_arg(tpf->ap, int);
	if (tpf->valprec < 0)
	{
		tpf->fprecision = FALSE;
		tpf->valprec = 0;
	}
}

int		ft_wildcard(t_tab *tpf, int i)
{
	if (tpf->fprecision == TRUE)
		ft_wildcard_prec(tpf);
	else
		ft_wildcard_width(tpf);
	return (i + 1);
}
