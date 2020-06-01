/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usefull_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:55:17 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 11:04:15 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

long	ft_usefull_free(long val_ret, void *ptr)
{
	wrfree(ptr);
	return (val_ret);
}
