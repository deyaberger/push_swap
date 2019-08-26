/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:48:46 by dberger           #+#    #+#             */
/*   Updated: 2019/08/26 12:05:33 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void		ft_first_instruct(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	int		nb;
	int		i;

	tmp = a->first;
	i = 0;
	while (i < 2)
	{
		while (a->size > 3 
			&& (tmp->nb == a->max || tmp->nb == a->max2 || tmp->nb == a->max3))
			tmp = tmp->next;
		if (tmp->nb != a->max && tmp->nb != a->max2 && tmp->nb != a->max3)
		{
			write (0, "pb\n", 3);
			nb = ft_del_elem(a);
			ft_push(b, nb);
		}
		tmp = a->first;
		i++;
	}
}

t_instr		*ft_count_rb(t_stack *b, t_instr *list, t_elem *tmp)
{
	t_elem *comp;
	t_elem *last;

	comp = b->first;
	last = b->last;
	if (tmp->nb < comp->nb && comp->nb != b->max)
	{
		while (tmp->nb < comp->nb && comp->nb != b->max && comp)
		{
			list->rb = list->rb + 1;
			comp = comp->next;
		}
		return (list);
	}
	if (tmp->nb < comp->nb && comp->nb == b->max || tmp->nb > comp->nb && comp->nb != b->max)
	{
		if (tmp->nb < last)
			return (list);
		if (tmp->nb > last)
		{
			while (tmp->nb > comp->nb && comp->nb != b->max)
			{
				list->rb = list->rb + 1;
				comp = comp->next;
			}
			while (tmp->nb < comp->nb)
			{
				list->rb = list->rb + 1;
				comp = comp->next;
			}
		}
	}
	return (list);
}

void		ft_count_instr(t_stack *a, t_stack *b, t_instr *list, t_elem *tmp)
{
	list->ra = tmp->rank - 1;
	list->rra = a->size - rank;
	list = ft_count_rb(b, list, tmp);
	list->rrb = b->size - list->rb;
//	ft_count_rr_rrr;

}

int			ft_arrange(t_stack *a, t_stack *b, int argc)
{
	t_instr		*good;
	t_instr		*compare;
	t_elem		*tmp;
	int			i;
	int			nb;
	
	i = 0;
	if (!(good = (t_instr *)malloc(sizeof(*good))))
		return (0);
	if (!(compare = (t_instr *)malloc(sizeof(*compare))))
		return (0);
	if (argc > 3 && b->size == 0)
		ft_first_instruct(a, b);
	while (a)
	{
		tmp = a->first;
		while (tmp)
		{
			tmp->rank = i + 1;
			if (tmp == a->first)
				ft_count_instr(a, b, good, tmp);
			if (tmp->next)
				tmp = tmp->next;
			ft_count_instr(a, b, compare, tmp);
			ft_printf("good->total=%d, compare->total=%d\n", good->total, compare->total);
			if (compare->total < good->total)
				good = compare;
			i++;
		}
		write(0, "pb\n", 3);
		nb = ft_del_elem(a);
		ft_push(b, nb);
	}
	ft_printf("a = \n");
	ft_list_print(a, 1);
	ft_printf("b = \n");
	ft_list_print(b, 1);
	return (1);
}
