/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:07:07 by dberger           #+#    #+#             */
/*   Updated: 2019/08/30 14:44:10 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_arrange_max2(t_stack *a, t_stack *b, t_elem *elem)
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

void		ft_arrange_max1(t_stack *a, t_stack *b, t_elem *elem)
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

void		ft_arrange_a(t_stack *a, t_stack *b)
{
	t_elem *elem;

	elem = a->first;
	if (elem->nb == a->max1)
		ft_arrange_max1(a, b, elem);
	else if (elem->nb == a->max2)
		ft_arrange_max2(a, b, elem);
	else if (elem->nb == a->max3)
		if (elem->next->nb == a->max1)
		{
			ft_swap(a);
			ft_print_instr(a, b, "sa\n", 2);
			ft_rotate(a, 1);
			ft_print_instr(a, b, "ra\n", 2);
		}
}

t_elem		*ft_give_rank(t_stack *b)
{
	int		i;
	t_elem	*elem;

	i = 1;
	elem = b->first;
	elem->rank = i;
	while (elem && elem->nb != b->max1)
	{
		elem = elem->next;
		elem->rank = i + 1;
		i++;
	}
	return (elem);
}

int			ft_finish_swap(t_stack *a, t_stack *b)
{
	t_elem	*elem;
	int		i;
	int		mode;

	ft_arrange_a(a, b);
	if (b->size == 0)
		return (0);
	elem = ft_give_rank(b);
	i = elem->rank - 1 <= b->size - elem->rank - 1 ?
		elem->rank - 1 : b->size - elem->rank - 1;
	mode = elem->rank - 1 <= b->size - elem->rank - 1 ? 1 : 2;
	while (i--)
	{
		ft_rotate(b, mode);
		if (mode == 1)
			ft_print_instr(a, b, "rb\n", 2);
		if (mode == 2)
			ft_print_instr(a, b, "rrb\n", 2);
	}
	while (b->size != 0)
	{
		ft_push(a, ft_del_elem(b));
		ft_print_instr(a, b, "pa\n", 2);
	}
	return (1);
}
