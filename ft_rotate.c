/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:59:03 by dberger           #+#    #+#             */
/*   Updated: 2019/08/09 16:20:27 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rotate(t_stack *pile, int mode)
{
	t_elem	*top;
	t_elem	*bottom;
	t_elem	*link;
	int		s;

	s = 1;
	if (!pile->first)
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
		top->next = NULL;
	}
	else if (mode == 2)
	{
		pile->first = bottom;
		bottom->next = top;
		link = top;
		while (s < pile->size - 1)
		{
			link = link->next;
			s++;
		}
		link->next = NULL;
	}
	return (1);
}
