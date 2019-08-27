/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:48:46 by dberger           #+#    #+#             */
/*   Updated: 2019/08/27 16:46:48 by dberger          ###   ########.fr       */
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
			write(0, "pb\n", 3);
			nb = ft_del_elem(a);
			ft_push(b, nb);
		}
		tmp = a->first;
		i++;
	}
}

void	ft_rotate_n(t_stack *pile, int mode, int x, char *str)
{
	while (x > 0)
	{
		ft_rotate(pile, mode);
		x--;
	}
	if (str[0] != '\0')
		write(0, str, ft_strlen(str));
}

void	ft_do_instruct(t_stack *a, t_stack *b, t_instr *good)
{
	int		i;
	int		mode;

	i = 0;
	mode = 0;
	if (good->ra != 0)
		ft_rotate_n(a, 1, good->ra, "ra\n");
	if (good->rra != 0)
		ft_rotate_n(a, 2, good->rra, "rra\n");
	if (good->rb != 0)
		ft_rotate_n(b, 1, good->rb, "rb\n");
	if (good->rrb != 0)
		ft_rotate_n(b, 2, good->rrb, "rrb\n");
	if (good->rr != 0)
	{
		ft_rotate_n(a, 1, good->rr, "");
		ft_rotate_n(b, 1, good->rr, "rr\n");
	}
	if (good->rrr != 0)
	{
		ft_rotate_n(a, 2, good->rrr, "");
		ft_rotate_n(b, 2, good->rrr, "rrr\n");
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
}

int		ft_arrange(t_stack *a, t_stack *b, int argc)
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
		write(0, "pb\n", 3);
		i = ft_del_elem(a);
		ft_push(b, i);
	}
	return (1);
}
