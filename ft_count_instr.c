/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:21:40 by dberger           #+#    #+#             */
/*   Updated: 2019/09/02 17:37:18 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_elem	*ft_browse_stack(t_instr *list, t_elem *comp)
{
	list->rb = list->rb + 1;
	comp = comp->next;
	return (comp);
}

int		ft_count_rb(t_stack *b, t_instr *list, int nb)
{
	t_elem *comp;

	comp = b->first;
	if (nb < comp->nb)
	{
		while (nb < comp->nb && comp->next && comp->nb != b->max1)
			comp = ft_browse_stack(list, comp);
		return (0);
	}
	if ((nb < comp->nb && comp->nb == b->max1)
			|| (nb > comp->nb && comp->nb != b->max1))
	{
		if (nb < b->last->nb)
			return (0);
		if (nb > b->last->nb)
		{
			while (nb > comp->nb && comp->nb != b->max1 && comp)
				comp = ft_browse_stack(list, comp);
			if (comp->nb == b->max1 && nb > b->max1)
				return (0);
			while (nb < comp->nb && comp)
				comp = ft_browse_stack(list, comp);
		}
	}
	return (0);
}

void	ft_merge_a_b(t_instr *list, int mode)
{
	if (mode == 1)
	{
		list->rr = list->ra <= list->rb ? list->ra : list->rb;
		list->rra = 0;
		list->rrb = 0;
		if (list->ra <= list->rb && (list->ra = 0) == 0)
			list->rb = list->rb - list->rr;
		else if (list->ra > list->rb && (list->rb = 0) == 0)
			list->ra = list->ra - list->rr;
	}
	if (mode == 2)
	{
		list->rrr = list->rra <= list->rrb ? list->rra : list->rrb;
		list->ra = 0;
		list->rb = 0;
		if (list->rra <= list->rrb && (list->rra = 0) == 0)
			list->rrb = list->rrb - list->rrr;
		else if (list->rrb < list->rra && (list->rrb = 0) == 0)
			list->rra = list->rra - list->rrr;
	}
}

void	ft_count_rr_rrr(t_instr *list)
{
	int		total1;
	int		total2;
	int		total3;

	total1 = 0;
	total2 = 0;
	total3 = 0;
	total1 = list->ra <= list->rra ? list->ra : list->rra;
	total1 = list->rb <= list->rrb ? total1 + list->rb : total1 + list->rrb;
	total2 = list->ra <= list->rb ? list->rb : list->ra;
	total3 = list->rra <= list->rrb ? list->rrb : list->rra;
	if (total1 <= total2 && total1 <= total3)
	{
		list->rra = list->ra <= list->rra ? 0 : list->rra;
		list->ra = list->rra == 0 ? list->ra : 0;
		list->rrb = list->rb <= list->rrb ? 0 : list->rrb;
		list->rb = list->rrb == 0 ? list->rb : 0;
	}
	else if (total2 < total1 && total2 <= total3)
		ft_merge_a_b(list, 1);
	else if (total3 < total1 && total3 < total2)
		ft_merge_a_b(list, 2);
}

void	ft_count_instr(t_stack *a, t_stack *b, t_instr *list, t_elem *tmp)
{
	list->ra = 0;
	list->rra = 0;
	list->rb = 0;
	list->rrb = 0;
	list->rr = 0;
	list->rrr = 0;
	list->total = 0;
	list->ra = tmp->rank - 1;
	if (list->ra != 0)
		list->rra = a->size - list->ra;
	ft_count_rb(b, list, tmp->nb);
	if (list->rb != 0)
		list->rrb = b->size - list->rb;
	list->total = list->ra + list->rra + list->rb + list->rrb
		+ list->rr + list->rrr;
	ft_count_rr_rrr(list);
	list->total = list->ra + list->rra + list->rb + list->rrb
		+ list->rr + list->rrr;
}
