/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:59:03 by dberger           #+#    #+#             */
/*   Updated: 2019/09/04 16:14:06 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rot_down(t_stack *pile, t_elem *bottom, t_elem *top, t_elem *link)
{
	int		s;

	s = 1;
	pile->first = bottom;
	bottom->next = top;
	link = top;
	while (s < pile->size - 1)
	{
		link = link->next;
		s++;
	}
	pile->last = link;
	link->next = NULL;
}

int		ft_rotate(t_stack *pile, int mode)
{
	t_elem	*top;
	t_elem	*bottom;
	t_elem	*link;

	if (!pile->first || pile->size == 1)
		return (0);
	top = pile->first;
	link = top;
	while (link->next)
		link = link->next;
	bottom = link;
	if (mode == 1)
	{
		pile->first = top->next;
		bottom->next = top;
		pile->last = top;
		top->next = NULL;
	}
	else if (mode == 2)
		ft_rot_down(pile, bottom, top, link);
	return (1);
}
