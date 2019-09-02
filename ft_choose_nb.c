/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:10:46 by dberger           #+#    #+#             */
/*   Updated: 2019/09/02 17:45:38 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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

t_instr	*ft_choose_nb(t_stack *a, t_stack *b, t_instr *good, t_instr *compare)
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
			ft_count_instr(a, b, good, tmp);
		tmp = tmp->next;
		if (tmp && tmp->nb != a->max1 && tmp->nb != a->max2
				&& tmp->nb != a->max3)
		{
			rank = ft_ranking(a, &tmp, rank + 1);
			ft_count_instr(a, b, compare, tmp);
			if (compare->total < good->total)
				good = compare;
		}
	}
	return (good);
}
