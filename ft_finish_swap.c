/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:07:07 by dberger           #+#    #+#             */
/*   Updated: 2019/08/29 19:53:39 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_arrange_a(t_stack *a, t_stack *b)
{
	t_elem *elem;

	elem = a->first;
	if (elem->nb == a->max1)
	{
		if (elem->next->nb == a->max3)
		{
			ft_rotate(a, 1);
			ft_print_instr(a, b, "ra\n", 2);
		}
		else if (elem->next->nb == a->max2)
		{
			ft_rotate(a, 1);
			ft_print_instr(a, b, "ra\n", 2);
			ft_swap(a);
			ft_print_instr(a, b, "sa\n", 2);
		}
	}
	else if (elem->nb == a->max2)
	{
		if (elem->next->nb == a->max3)
		{
			ft_swap(a);
			ft_print_instr(a, b, "sa\n", 2);
		}
		else if (elem->next->nb == a->max1)
		{
			ft_rotate(a, 2);
			ft_print_instr(a, b, "rra\n", 2);
		}
	}
	else if (elem->nb == a->max3)
	{
		if (elem->next->nb == a->max1)
		{
			ft_swap(a);
			ft_print_instr(a, b, "sa\n", 2);
			ft_rotate(a, 1);
			ft_print_instr(a, b, "ra\n", 2);
		}
	}
}

int		ft_finish_swap(t_stack *a, t_stack *b)
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
	ft_arrange_a(a, b);
	if (b->size == 0)
		return (0);
	elem = b->first;
	elem->rank = i;
	while (b->size != 0 && elem && elem->nb != b->max1)
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
	return (1);
}
