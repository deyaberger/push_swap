/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:48:46 by dberger           #+#    #+#             */
/*   Updated: 2019/08/26 19:18:32 by dberger          ###   ########.fr       */
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

t_instr		*ft_count_rb(t_stack *b, t_instr *list, int nb)
{
	t_elem *comp;
	t_elem *last;

	comp = b->first;
	last = b->last;
	if (nb < comp->nb)
	{
		while (nb < comp->nb && comp->next)
		{
			list->rb = list->rb + 1;
			comp = comp->next;
		}
		return (list);
	}
	if ((nb < comp->nb && comp->nb == b->max) || (nb > comp->nb && comp->nb != b->max))
	{
		if (nb < last->nb)
			return (list);
		if (nb > last->nb)
		{
			while (nb > comp->nb && comp->nb != b->max && comp)
			{
				list->rb = list->rb + 1;
				comp = comp->next;
			}
			if (comp->nb == b->max && nb > b->max)
				return (list);
			while (nb < comp->nb && comp)
			{
				list->rb = list->rb + 1;
				comp = comp->next;
			}
		}
	}
	return (list);
}

void		ft_count_rr_rrr(t_instr *list)
{
	int		total1;
	int		total2;
	int		total3;

	total1 = 0;
	total2 = 0;
	total3 = 0;
	if (list->ra <= list->rra)
		total1 = list->ra;
	else
		total1 = list->rra;
	if (list->rb <= list->rrb)
		total1 = total1 + list->rb;
	else
		total1 = total1 + list->rrb;
	if (list->ra <= list->rb)
		total2 = list->rb;
	else
		total2 = list->ra;
	if (list->rra <= list->rrb)
		total3 = list->rrb;
	else
		total3 = list->rra;
	ft_printf("total1= %d, total2= %d, total3= %d\n", total1, total2, total3);
	if (total1 <= total2 && total1 <= total3)
	{
		if (list->ra <= list->rra)
			list->rra = 0;
		else
			list->ra = 0;
		if (list->rb <= list->rrb)
			list->rrb = 0;
		else
			list->rb = 0;
	}
	else if (total2 < total1 && total2 <= total3)
	{
		if (list->ra <= list->rb)
		{
			list->rr = list->ra;
			list->rb = list->rb - list->rr;
			list->ra = 0;
			list->rra = 0;
			list->rrb = 0;
			ft_printf("list->rr= %d\n", list->rr);
		}
		else if (list->ra > list->rb)
		{
			list->rr = list->rb;
			list->ra = list->ra - list->rr;
			list->rb = 0;
			list->rra = 0;
			list->rrb = 0;
		}
	}
	else if (total3 < total1 && total3 < total2)
	{
		if (list->rra <= list->rrb)
		{
			list->rrr = list->rra;
			list->rrb = list->rrb - list->rrr;
			list->rra = 0;
			list->ra = 0;
			list->rb = 0;
		}
		else if (list->rrb < list->rra)
		{
			list->rrr = list->rrb;
			list->rra = list->rra - list->rrr;
			list->rrb = 0;
			list->ra = 0;
			list->rb = 0;
		}

	}
}

void		ft_count_instr(t_stack *a, t_stack *b, t_instr *list, t_elem *tmp)
{
	list->ra = 0;
	list->rra = 0;
	list->rb = 0;
	list->rrb = 0;
	list->rr = 0;
	list->rrr = 0;
	list->ra = tmp->rank - 1;
	if (list->ra != 0)
		list->rra = a->size - tmp->rank + 1;
	list = ft_count_rb(b, list, tmp->nb);
	if (list->rb != 0)
		list->rrb = b->size - list->rb;
	list->total = list->ra + list->rra + list->rb + list->rrb + list->rr + list->rrr;
	ft_printf(" \n BEFORE CHANGE RR: \nra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d, total list = %d\n", list->ra, list->rra, list->rb, list->rrb, list->rr, list->rrr, list->total);
	ft_count_rr_rrr(list);
	list->total = list->ra + list->rra + list->rb + list->rrb + list->rr + list->rrr;
	ft_printf("\n AFTER CHANGE RR: \nra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d, total list = %d\n", list->ra, list->rra, list->rb, list->rrb, list->rr, list->rrr, list->total);
}

void	ft_rotate_n(t_stack *pile, int mode, int x)
{
	while (x > 0)
	{
		ft_rotate(pile, mode);
		x--;
	}
}

void	ft_do_instruct(t_stack *a, t_stack *b, t_instr *good)
{
	int		i;
	int		mode;

	i = 0;
	mode = 0;
	ft_printf("\n ***** \nGOOD: \nra = %d, rra = %d, rb = %d, rrb = %d, rr = %d, rrr = %d, total good = %d\n", good->ra, good->rra, good->rb, good->rrb, good->rr, good->rrr, good->total);
	if (good->ra != 0)
	{
		ft_rotate_n(a, 1, good->ra);
		write(0, "ra\n", 3);
	}
	if (good->rra != 0)
	{
		ft_rotate_n(a, 2, good->rra);
		write(0, "rra\n", 4);
	}
	if (good->rb != 0)
	{
		ft_rotate_n(b, 1, good->rb);
		write(0, "rb\n", 4);
	}
	if (good->rrb != 0)
	{
		ft_rotate_n(b, 2, good->rrb);
		write(0, "rrb\n", 4);
	}
	if (good->rr != 0)
	{
		ft_rotate_n(a, 1, good->rr);
		ft_rotate_n(b, 1, good->rr);
		write(0, "rr\n", 3);
	}
	if (good->rrr != 0)
	{
		ft_rotate_n(a, 2, good->rrr);
		ft_rotate_n(b, 2, good->rrr);
		write(0, "rrr\n", 4);
	}
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
	ft_printf("a = \n");
	ft_list_print(a, 1);
	ft_printf("b = \n");
	ft_list_print(b, 1);
	while (a->size != 0)
	{
		tmp = a->first;
		while (tmp)
		{
			tmp->rank = i + 1;
			if (tmp == a->first)
			{
				ft_count_instr(a, b, good, tmp);
				compare = good;
			}
			tmp = tmp->next;
			if (tmp)
			{
				tmp->rank = i + 2;
				ft_count_instr(a, b, compare, tmp);
			}
			if (compare->total < good->total)
				good = compare;
			i++;
		}
		i = 0;
		ft_do_instruct(a, b, good);
		write(0, "pb\n", 3);
		nb = ft_del_elem(a);
		ft_push(b, nb);
		ft_printf("a = \n");
		ft_list_print(a, 1);
		ft_printf("b = \n");
		ft_list_print(b, 1);
	}
	return (1);
}
