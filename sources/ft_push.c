/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:54:56 by dberger           #+#    #+#             */
/*   Updated: 2019/08/29 15:01:38 by dberger          ###   ########.fr       */
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
	if (!pile->first && !pile->last)
		pile->last = new;
	if (pile->first)
		new->next = pile->first;
	pile->first = new;
}
