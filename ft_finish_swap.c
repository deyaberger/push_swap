/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:07:07 by dberger           #+#    #+#             */
/*   Updated: 2019/08/27 18:49:09 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_finish_swap(t_stack *a, t_stack *b)
{
	t_elem	*elem;
	int		i;
	int		rb;
	int		rrb;
	int		mode;
	int		nb;

	i = 1;
	rb = 0;
	rrb = 0;
	elem = b->first;
	elem->rank = i;
	while (elem && elem->nb != b->max)
	{
		elem = elem->next;
		elem->rank = i + 1;
		i++;
	}
	rb = elem->rank - 1;
	rrb = b->size - rb;
	i = rb <= rrb ? rb : rrb;
	mode = rb <= rrb ? 1 : 2;
	while (i > 0)
	{
		ft_rotate(b, mode);
		if (mode == 1)
			ft_print_instr(a, b, "rb\n", 2);
		if (mode == 2)
			ft_print_instr(a, b, "rrb\n", 2);
		i--;
	}
	i = b->size;
	while (i > 0)
	{
		nb = ft_del_elem(b);
		ft_push(a, nb);
		ft_print_instr(a, b, "pa\n", 2);
		i--;
	}
}
