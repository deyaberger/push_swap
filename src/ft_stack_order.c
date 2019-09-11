/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:01:27 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 17:23:56 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** We compare every number to the first element and make sure that they are
** all superior to it, then we move to the second element and do the same
** comparision until we have done it for every link of the chain
*/

int		ft_stack_order(t_stack *a, t_stack *b)
{
	int		nbr;
	t_elem	*elem;
	t_elem	*scnd_elem;

	if (b->size != 0)
		return (0);
	elem = a->first;
	nbr = elem->nb;
	if (nbr != a->min)
		return (0);
	scnd_elem = elem->next;
	while (elem->next)
	{
		while (scnd_elem)
		{
			if (nbr > scnd_elem->nb)
				return (0);
			scnd_elem = scnd_elem->next;
		}
		elem = elem->next;
		nbr = elem->nb;
		if (elem->next)
			scnd_elem = elem->next;
	}
	return (1);
}
