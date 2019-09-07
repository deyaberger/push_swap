/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:21:40 by dberger           #+#    #+#             */
/*   Updated: 2019/09/07 17:51:01 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		while (nb < comp->nb && comp->next && comp->nb != b->max1)
			comp = ft_browse_stack(list, comp);
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

void	ft_count_rr_rrr(t_instr *list)
{
	int		total1;
	int		total2;
	int		total3;
	int		total4;

	total1 = list->ra <= list->rb ? list->rb : list->ra;
	total2 = list->rra <= list->rrb ? list->rrb : list->rra;
	total3 = list->ra + list->rrb;
	total4 = list->rra + list->rb;
	if (total1 <= total2 && total1 <= total3 && total1 <= total4)
	{
		list->rra = 0;
		list->rrb = 0;
		list->rr = list->ra <= list->rb ? list->ra : list->rb;
		list->ra = list->ra <= list->rb ? 0 : list->ra - list->rr;
		list->rb = list->ra == 0 ? list->rb - list->rr : 0;
	}
	else if (total2 < total1 && total2 <= total3 && total2 <= total4)
	{
		list->ra = 0;
		list->rb = 0;
		list->rrr = list->rra <= list->rrb ? list->rra : list->rrb;
		list->rra = list->rra <= list->rrb ? 0 : list->rra - list->rrr;
		list->rrb = list->rra == 0 ? list->rrb - list->rrr : 0;

	}
	else if (total3 < total1 && total3 < total2 && total3 <= total4)
	{
		list->rra = 0;
		list->rb = 0;
	}
	else if (total4 < total1 && total4 < total2 && total4 < total3)
	{
		list->ra = 0;
		list->rrb = 0;
	}
}

t_instr	*ft_count_instr(t_stack *a, t_stack *b, t_instr *list, t_elem *tmp)
{
	list->sa = 0;
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
	return (list);
}
