/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:54:56 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 17:25:59 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_elem		*ft_create_elem(int n)
{
	t_elem *new;

	if (!(new = (t_elem *)malloc(sizeof(*new))))
		return (NULL);
	new->nb = n;
	new->rank = 0;
	new->next = NULL;
	return (new);
}

/*
** To add a new element to a stack, we first create it, gives a number
** corresponding to it in "new->nb". Then we attached it (with new->next)
** to the top of the stack we want to put it in, and finally
** redirects the top of this stack (pile->first) to this new element.
** We also check if it is one of the 3 maximums of the pile.
*/

void		ft_push(t_stack *pile, int n)
{
	t_elem	*new;

	new = ft_create_elem(n);
	if (new->nb >= pile->max1)
	{
		pile->max3 = pile->max2;
		pile->max2 = pile->max1;
		pile->max1 = new->nb;
	}
	if (new->nb >= pile->max2 && new->nb < pile->max1)
	{
		pile->max3 = pile->max2;
		pile->max2 = new->nb;
	}
	if (new->nb >= pile->max3 && new->nb < pile->max2)
		pile->max3 = new->nb;
	if (new->nb <= pile->min)
		pile->min = new->nb;
	pile->size = pile->size + 1;
	if (!pile->last)
		pile->last = new;
	if (pile->first)
		new->next = pile->first;
	pile->first = new;
}
