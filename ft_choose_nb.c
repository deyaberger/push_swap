/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:10:46 by dberger           #+#    #+#             */
/*   Updated: 2019/09/02 15:14:27 by dberger          ###   ########.fr       */
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

void	ft_choose_nb(t_stack *a, t_stack *b, t_instr *good, t_instr *compare)
{
	int		rank;
	int		count;
	t_elem	*tmp;

	count = 0;
	rank = 1;
	tmp = a->first;
	while (tmp->next)
	{
		rank = ft_ranking(a, &tmp, rank);
		if ((count == 0 || (tmp == a->last && (tmp->nb == a->max1
			|| tmp->nb == a->max2 || tmp->nb == a->max3))) && (count = 1) == 1)
			ft_count_instr(a, b, good, tmp);
		tmp = tmp->next;
		rank = ft_ranking(a, &tmp, rank + 1);
		if (tmp)
			ft_count_instr(a, b, compare, tmp);
		if (tmp && tmp->nb != a->max1 && tmp->nb != a->max2
				&& tmp->nb != a->max3 && compare->total < good->total)
			good = compare;
	}
}