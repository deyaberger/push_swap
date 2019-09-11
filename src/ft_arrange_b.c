/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:05:38 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 15:59:07 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** First instructions necessary to start sorting numbers from A to B
** At least 2 numbers are needed in B to be able to start the sorting
*/

void	ft_first_instruct(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	int		nb;
	int		i;

	i = 0;
	while (a->size > 3 && i < 2)
	{
		tmp = a->first;
		while (tmp && (tmp->nb == a->max1
					|| tmp->nb == a->max2 || tmp->nb == a->max3))
		{
			ft_rotate(a, 1);
			ft_print_instr(a, b, "ra\n", 2);
			tmp = a->first;
		}
		if (tmp->nb != a->max1 && tmp->nb != a->max2
			&& tmp->nb != a->max3 && a->first)
		{
			nb = ft_del_elem(a);
			ft_push(b, nb);
			ft_print_instr(a, b, "pb\n", 2);
		}
		i++;
	}
}

/*
** Applies the best option of instructions stocked in t_instr to the pile A
*/

void	ft_send_instr(t_stack *a, t_stack *b, t_instr *good)
{
	int		i;
	int		mode;

	i = 0;
	mode = 0;
	if (good->ra != 0)
		ft_do_instruct(a, b, "ra\n", good->ra);
	if (good->rra != 0)
		ft_do_instruct(a, b, "rra\n", good->rra);
	if (good->rb != 0)
		ft_do_instruct(a, b, "rb\n", good->rb);
	if (good->rrb != 0)
		ft_do_instruct(a, b, "rrb\n", good->rrb);
	if (good->rr != 0)
	{
		ft_do_instruct(a, b, "1", good->rr);
		ft_do_instruct(a, b, "rr\n", good->rr);
	}
	if (good->rrr != 0)
	{
		ft_do_instruct(a, b, "2", good->rrr);
		ft_do_instruct(a, b, "rrr\n", good->rrr);
	}
}

/*
** Puts all the numbers of the pile A in the pile B in the good order
** Except the 3 maximums of A that don't move out of the pile
*/

int		ft_arrange_b(t_stack *a, t_stack *b)
{
	t_instr		*good;
	t_instr		*compare;

	if (!(good = (t_instr *)malloc(sizeof(*good))))
		return (0);
	if (!(compare = (t_instr *)malloc(sizeof(*compare))))
		return (0);
	ft_first_instruct(a, b);
	while (a->size > 3)
	{
		ft_choose_nb(a, b, good, compare);
		ft_send_instr(a, b, good);
		ft_push(b, ft_del_elem(a));
		ft_print_instr(a, b, "pb\n", 2);
	}
	free(good);
	free(compare);
	return (1);
}
