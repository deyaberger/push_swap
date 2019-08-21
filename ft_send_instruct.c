/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:19:59 by dberger           #+#    #+#             */
/*   Updated: 2019/08/21 17:56:07 by dberger          ###   ########.fr       */
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

void		ft_count_rra(t_stack *a, t_stack *b, t_instr *count)
{
	int		nb;
	int		ranka;
	int		rankb;
	t_elem	*tmp;
	t_elem	*tmpb;

	ranka = 1;
	rankb = 1;
	tmp = a->first;
	tmpb = b->first;
	while (a->size > 3 
		&& (tmp->nb == a->max || tmp->nb == a->max2 || tmp->nb == a->max3))
	{
		tmp = tmp->next;
		rank += 1;
	}
	nb = tmp->nb;
	count->ra = rank - 1;
	count->rra = a->size - rank;
	rank = 1;
	while (nb > tmpb->nb && tmpb)
	{
		tmpb = tmpb->next;
		rank += 1;
	}
	while (rank > 1)
	{
		count->rb += 1;
		rank--;
	}
	ft_printf("nb = %d\n", nb);
	ft_printf("count->ra= %d, count->rb=%d, count->rra= %d, count->rrb = %d"
}

int			ft_send_instruct(t_stack *a, t_stack *b)
{
	t_instr		*count;

	if (!(count = (t_instr *)malloc(sizeof(*count))))
		return (0);
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	if (b->size == 0)
		ft_first_instruct(a, b);
	while (a)
	{
		tmp = a->first;
		while (tmp)
		{
			nb principal = total de ft_remplir_instruct;
			nb principal ra = ...;

			tmp = tmp->next;
			nb2 = total de ft_remplir_instruct;
			if (nb principal < nb2)
				nb principal = nb2;
		}
		pb;
	}
	ft_printf("a = \n");
	ft_list_print(a, 1);
	ft_printf("b = \n");
	ft_list_print(b, 1);
	ft_count_instruct(a, b, count);
	return (1);
}
