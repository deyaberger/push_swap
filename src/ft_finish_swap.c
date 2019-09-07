/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:07:07 by dberger           #+#    #+#             */
/*   Updated: 2019/09/07 13:25:33 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_arrange_a(t_stack *a, t_stack *b, t_instr *list)
{
	t_elem *elem;

	elem = a->first;
	if (elem->nb == a->max1)
	{
		if (elem->next->nb == a->max3)
			list->ra = 1;
		else if (elem->next->nb == a->max2)
		{
			list->ra = 1;
			list->sa = 2;
		}
	}
	else if (elem->nb == a->max2)
	{
		if (elem->next->nb == a->max3)
			list->sa = 1;
		else if (elem->next->nb == a->max1)
			list->rra = 1;
	}
	else if (elem->nb == a->max3)
		if (elem->next->nb == a->max1)
		{
			list->sa = 1;
			list->ra = 1;
		}
}

t_elem		*ft_give_rank(t_stack *b)
{
	int		i;
	t_elem	*elem;

	i = 1;
	if (b->first)
	{
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
	return (NULL);
}

void		ft_finish_instr(t_stack *a, t_stack *b, t_instr *list)
{
	int		i;

	i = 0;
	if (list->sa == 1)
	{
		ft_swap(a);
		ft_print_instr(a, b, "sa\n", 2);
	}
	if (list->ra == 1)
	{
		ft_rotate(a, 1);
		ft_print_instr(a, b, "ra\n", 2);
	}
	if (list->rra == 1)
	{
		ft_rotate(a, 2);
		ft_print_instr(a, b, "rra\n", 2);
	}
	if (list->rr == 1)
	{
		ft_rotate(a, 1);
		ft_rotate(b, 1);
		ft_print_instr(a, b, "rr\n", 2);
	}
	if (list->rrr == 1)
	{
		ft_rotate(a, 2);
		ft_rotate(b, 2);
		ft_print_instr(a, b, "rrr\n", 2);
	}
	if (b->first && list->rb)
	{
		i = list->rb;
		while (i)
		{
			ft_rotate(b, 1);
			ft_print_instr(a, b, "rb\n", 2);
			i--;
		}
	}
	if (b->first && list->rrb)
	{
		i = list->rb;
		while (i)
		{
			ft_rotate(b, 2);
			ft_print_instr(a, b, "rrb\n", 2);
			i--;
		}
	}
	if (list->sa == 2)
	{
		ft_swap(a);
		ft_print_instr(a, b, "sa\n", 2);
	}
}

int			ft_finish_swap(t_stack *a, t_stack *b)
{
	t_elem	*elem;
	int		i;
	int		mode;
	t_instr	*list;

	if (!(list = (t_instr *)malloc(sizeof(*list))))
		return (0);
	list->sa = 0;
	list->ra = 0;
	list->rra = 0;
	list->rb = 0;
	list->rrb = 0;
	list->rr = 0;
	list->rrr = 0;
	list->total = 0;
	if (a->size < 3)
	{
		if (a->first->nb > a->first->next->nb)
		{
			ft_swap(a);
			ft_print_instr(a, b, "sa\n", 2);
		}
		return (0);
	}
	ft_arrange_a(a, b, list);
	elem = ft_give_rank(b);
	if (b->first)
	{
		list->rb = elem->rank - 1 <= b->size - elem->rank + 1 ?
			elem->rank - 1: 0;
		list->rrb = elem->rank - 1 <= b->size - elem->rank + 1? 0 : b->size - elem->rank + 1;
		if (list->ra && list->rb)
		{
			list->rr = list->ra;
			list->ra = 0;
			list->rb = list->rb - list->rr;
		}
		if (list->rra && list->rrb)
		{
			list->rrr = list->rra;
			list->rra = 0;
			list->rrb = list->rrb - list->rrr;
		}
	}
	ft_finish_instr(a, b, list);
	while (b->size != 0)
	{
		ft_push(a, ft_del_elem(b));
		ft_print_instr(a, b, "pa\n", 2);
	}
	return (1);
}
