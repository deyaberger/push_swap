/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:05:38 by dberger           #+#    #+#             */
/*   Updated: 2019/09/09 17:12:49 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_rotate_n(t_stack *a, t_stack *b, int x, char *str)
{
	int		mode;
	t_stack	*pile;

	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n")
			|| !ft_strcmp(str, "rr\n") || !ft_strcmp(str, "1"))
		mode = 1;
	else
		mode = 2;
	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rra\n")
		|| !ft_strcmp(str, "1") || !ft_strcmp(str, "2"))
		pile = a;
	else
		pile = b;
	while (x > 0)
	{
		ft_rotate(pile, mode);
		if (ft_strcmp(str, "1") && ft_strcmp(str, "2"))
			ft_print_instr(a, b, str, 2);
		x--;
	}
}

void	ft_do_instruct(t_stack *a, t_stack *b, t_instr *good)
{
	int		i;
	int		mode;

	i = 0;
	mode = 0;
	if (good->ra != 0)
		ft_rotate_n(a, b, good->ra, "ra\n");
	if (good->rra != 0)
		ft_rotate_n(a, b, good->rra, "rra\n");
	if (good->rb != 0)
		ft_rotate_n(a, b, good->rb, "rb\n");
	if (good->rrb != 0)
		ft_rotate_n(a, b, good->rrb, "rrb\n");
	if (good->rr != 0)
	{
		ft_rotate_n(a, b, good->rr, "1");
		ft_rotate_n(a, b, good->rr, "rr\n");
	}
	if (good->rrr != 0)
	{
		ft_rotate_n(a, b, good->rrr, "2");
		ft_rotate_n(a, b, good->rrr, "rrr\n");
	}
}

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
		good = ft_choose_nb(a, b, good, compare);
		ft_do_instruct(a, b, good);
		ft_push(b, ft_del_elem(a));
		ft_print_instr(a, b, "pb\n", 2);
	}
	free(good);
	free(compare);
	return (1);
}
