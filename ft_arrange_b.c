/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:05:38 by dberger           #+#    #+#             */
/*   Updated: 2019/08/29 12:44:11 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	ft_first_instruct(t_stack *a, t_stack *b)
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
			nb = ft_del_elem(a);
			ft_push(b, nb);
			ft_print_instr(a, b, "pb\n", 2);
		}
		tmp = a->first;
		i++;
	}
}

void	ft_rotate_n(t_stack *a, t_stack *b, int x, char *str)
{
	int		mode;
	t_stack	*pile;

	if (!ft_strcmp(str, "ra\n")
		|| !ft_strcmp(str, "rb\n") || !ft_strcmp(str, "rr\n"))
		mode = 1;
	else
		mode = 2;
	if (!ft_strcmp(str, "ra\n")
		|| !ft_strcmp(str, "rra\n") || !ft_strlen(str))
		pile = a;
	else
		pile = b;
	while (x > 0)
	{
		ft_rotate(pile, mode);
		x--;
	}
	if (str[0] != '\0')
		ft_print_instr(a, b, str, 2);
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
		ft_rotate_n(a, b, good->rr, "");
		ft_rotate_n(a, b, good->rr, "rr\n");
	}
	if (good->rrr != 0)
	{
		ft_rotate_n(a, b, good->rrr, "");
		ft_rotate_n(a, b, good->rrr, "rrr\n");
	}
}

void	ft_choose_nb(t_stack *a, t_stack *b, t_instr *good, t_instr *compare)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = a->first;
	while (tmp)
	{
		tmp->rank = i + 1;
		if (tmp == a->first)
			ft_count_instr(a, b, good, tmp);
		tmp = tmp->next;
		if (tmp)
		{
			tmp->rank = i + 2;
			ft_count_instr(a, b, compare, tmp);
		}
		if (tmp && compare->total < good->total)
			good = compare;
		i++;
	}
}

int		ft_arrange_b(t_stack *a, t_stack *b, int argc)
{
	t_instr		*good;
	t_instr		*compare;
	int			i;

	i = 0;
	if (!(good = (t_instr *)malloc(sizeof(*good))))
		return (0);
	if (!(compare = (t_instr *)malloc(sizeof(*compare))))
		return (0);
	if (argc > 3 && b->size == 0)
		ft_first_instruct(a, b);
	while (a->size != 0)
	{
		ft_choose_nb(a, b, good, compare);
		ft_do_instruct(a, b, good);
		i = ft_del_elem(a);
		ft_push(b, i);
		ft_print_instr(a, b, "pb\n", 2);
	}
	return (1);
}
