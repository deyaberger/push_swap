/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:07:07 by dberger           #+#    #+#             */
/*   Updated: 2019/09/12 15:39:04 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This function is called only when A has 3 numbers in it
** This calculates how to arrange A in 1 or 2 operations maximum
** It is the only time when we use the "sa" operation
*/

void		ft_arrange_a(t_stack *a, t_instr *list, t_elem *elem)
{
	list->sa = 0;
	list->ra = 0;
	list->rra = 0;
	list->rb = 0;
	list->rrb = 0;
	list->rr = 0;
	list->rrr = 0;
	list->total = 0;
	if (elem->nb == a->max1)
	{
		if (elem->next->nb == a->max3)
			list->ra = 1;
		else if (elem->next->nb == a->max2 && (list->ra = 1) == 1)
			list->sa = 2;
	}
	else if (elem->nb == a->max2)
	{
		if (elem->next->nb == a->max3)
			list->sa = 1;
		else if (elem->next->nb == a->max1)
			list->rra = 1;
	}
	else if (elem->nb == a->max3)
		if (elem->next->nb == a->max1 && (list->sa = 1) == 1)
			list->ra = 1;
}

/*
** Finds where is situated the max of B, to put it at the top of the list
** and be able to start doing "pa" as long as the list is not empty
*/

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

/*
** Sends the instructions once the final calculation of operations
** has been done - with the merges
*/

void		ft_finish_instr(t_stack *a, t_stack *b, t_instr *list)
{
	int		i;

	i = 0;
	if (list->sa == 1)
		ft_do_instruct(a, b, "sa\n", 1);
	if (list->ra == 1)
		ft_do_instruct(a, b, "ra\n", 1);
	if (list->rra == 1)
		ft_do_instruct(a, b, "rra\n", 1);
	if (list->rr == 1)
	{
		ft_do_instruct(a, b, "1", 1);
		ft_do_instruct(a, b, "rr\n", 1);
	}
	if (list->rrr == 1)
	{
		ft_do_instruct(a, b, "2", 1);
		ft_do_instruct(a, b, "rrr\n", 1);
	}
	if (b->first && list->rb)
		ft_do_instruct(a, b, "rb\n", list->rb);
	if (b->first && list->rrb)
		ft_do_instruct(a, b, "rrb\n", list->rrb);
	if (list->sa == 2)
		ft_do_instruct(a, b, "sa\n", 1);
}

/*
** There is only 1 ra or rra, not more, and maybe several rb or rrb
** so the merge here with rr is easier to calculate.
*/

void		ft_final_merge(t_instr *list, t_elem *elem, t_stack *b)
{
	if (b->first)
	{
		list->rb = elem->rank - 1 <= b->size - elem->rank + 1 ?
			elem->rank - 1 : 0;
		list->rrb = elem->rank - 1 <= b->size - elem->rank + 1 ?
			0 : b->size - elem->rank + 1;
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
}

/*
** Last operations needed: A should count 3 numbers,
** less if the argc was inferior in the first place.
** if B is not empty (if argc was > to 3) it has to be
** arrange from highest number to the lowest one, so there is only
** "pa" to do at the end
*/

int			ft_finish_swap(t_stack *a, t_stack *b)
{
	t_elem	*elem;
	t_instr	*list;

	if (!(list = (t_instr *)malloc(sizeof(*list))))
		return (0);
	if (a->size < 3)
	{
		if (a->first->nb > a->first->next->nb)
			ft_do_instruct(a, b, "sa\n", 1);
		return (0);
	}
	elem = a->first;
	ft_arrange_a(a, list, elem);
	elem = ft_give_rank(b);
	ft_final_merge(list, elem, b);
	ft_finish_instr(a, b, list);
	while (b->size != 0)
	{
		ft_push(a, ft_del_elem(b));
		ft_print_instr(a, b, "pa\n", 2);
	}
	free(list);
	return (1);
}
