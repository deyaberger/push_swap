/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:10:46 by dberger           #+#    #+#             */
/*   Updated: 2019/09/09 17:32:56 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Calculate the ranking of a number, to give it the right number
** of "ra" and "rra" necessary. It excludes the top 3 maximum of A
** to avoid useless operations
*/

int		ft_ranking(t_stack *a, t_elem **tmp, int rank)
{
	(*tmp)->rank = rank;
	while ((*tmp)->next && ((*tmp)->nb == a->max1
				|| (*tmp)->nb == a->max2 || (*tmp)->nb == a->max3))
	{
		(*tmp) = (*tmp)->next;
		(*tmp)->rank = rank + 1;
		rank++;
	}
	return (rank);
}

/*
** Good takes the values of compare since compare has "found" a number
** that requires less operations to be moved at the right place
*/

void	ft_update_good(t_instr *good, t_instr *compare)
{
	good->ra = compare->ra;
	good->rra = compare->rra;
	good->rb = compare->rb;
	good->rrb = compare->rrb;
	good->rr = compare->rr;
	good->rrr = compare->rrr;
	good->total = compare->total;
}

/*
** Choose the number in A that requires the least operations to be put in B
** Best options of operations stocked in t_instr good
*/

void	ft_choose_nb(t_stack *a, t_stack *b, t_instr *good, t_instr *compare)
{
	int		rank;
	int		count;
	t_elem	*tmp;

	count = 0;
	rank = 1;
	tmp = a->first;
	while (tmp && tmp->next)
	{
		rank = ft_ranking(a, &tmp, rank);
		if (count == 0 && tmp->nb != a->max1
				&& tmp->nb != a->max2 && tmp->nb != a->max3 && (count = 1) == 1)
			good = ft_count_instr(a, b, good, tmp);
		tmp = tmp->next;
		if (tmp)
		{
			rank = ft_ranking(a, &tmp, rank + 1);
			if (tmp->nb != a->max1 && tmp->nb != a->max2 && tmp->nb != a->max3)
			{
				compare = ft_count_instr(a, b, compare, tmp);
				if (compare->total < good->total)
					ft_update_good(good, compare);
			}
		}
	}
}
