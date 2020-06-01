/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:03:37 by aducas            #+#    #+#             */
/*   Updated: 2020/03/04 14:49:16 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_addr(t_tab *tpf, unsigned long adr, int argsize)
{
	if (tpf->width > 0)
		tpf->nbspace = tpf->width - argsize;
	if (tpf->nbspace < 0)
		tpf->nbspace = 0;
	if (tpf->fminus == TRUE)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(adr, "0123456789abcdef");
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
	else
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putstr_fd("0x", 1);
		ft_putnbr_base(adr, "0123456789abcdef");
	}
}

int			ft_display_addr(t_tab *tpf)
{
	unsigned long	adr;
	int				argsize;

	adr = va_arg(tpf->ap, unsigned long);
	argsize = ft_base(adr, "0123456789abcdef") + 2;
	if (tpf->fprecision && tpf->valprec == 0 && adr == 0 && tpf->width == 0)
	{
		ft_putstr_fd("0x", 1);
		argsize = 2;
	}
	else
		ft_addr(tpf, adr, argsize);
	tpf->length += argsize + tpf->nbspace;
	return (tpf->length);
}
