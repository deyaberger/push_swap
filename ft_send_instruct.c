/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:19:59 by dberger           #+#    #+#             */
/*   Updated: 2019/08/23 12:50:03 by dberger          ###   ########.fr       */
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

void		ft_count_instr(/*t_stack *a, t_stack *b, */t_instr *test, t_elem *tmp)
{
	if (tmp->nb == 3)
	{
		test->ra = 0;
		test->rra = 0;
		test->rr = 2;
		test->rrr = 0;
		test->rb = 0;
		test->rrb = 3;
		test->total = test->ra + test->rra + test->rr + test->rrr + test->rb + test->rrb;
	}
	if (tmp->nb == 6)
	{
		test->ra = 1;
		test->rra = 0;
		test->rr = 0;
		test->rrr = 0;
		test->rb = 1;
		test->rrb = 0;
		test->total = test->ra + test->rra + test->rr + test->rrr + test->rb + test->rrb;
	}

/*	ft_count_ra_rra;
	ft_count_rb_rrb;
	ft_count_rr_rrr;

	count->ra = rank - 1;
	count->rra = a->size - rank;*/
}

int			ft_send_instruct(t_stack *a, t_stack *b, int argc)
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
	while (/*a*/ i < 2)
	{
		tmp = a->first;
		while (/*tmp*/i < 2)
		{
			if (tmp == a->first)
				ft_count_instr(/*a, b,*/ good, tmp);
			if (tmp->next)
				tmp = tmp->next;
			ft_count_instr(/*a, b,*/ compare, tmp);
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