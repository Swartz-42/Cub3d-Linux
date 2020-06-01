/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:52:14 by gbendjaf          #+#    #+#             */
/*   Updated: 2020/03/04 14:50:41 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init(t_tab *tpf)
{
	tpf->fminus = FALSE;
	tpf->fzero = FALSE;
	tpf->fprecision = FALSE;
	tpf->width = 0;
	tpf->valprec = 0;
	tpf->nbspace = 0;
	tpf->nbzero = 0;
}
