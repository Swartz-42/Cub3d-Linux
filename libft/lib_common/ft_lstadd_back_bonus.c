/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:14:22 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 11:54:27 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current_elem;

	if (alst == 0)
		return ;
	if (*alst == 0)
	{
		*alst = new;
		return ;
	}
	current_elem = *alst;
	while (current_elem->next)
		current_elem = current_elem->next;
	current_elem->next = new;
}
