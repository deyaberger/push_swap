/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:54:56 by dberger           #+#    #+#             */
/*   Updated: 2019/08/13 15:09:25 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_elem		*ft_create_elem(int n)
{
	t_elem *new;

	if (!(new = (t_elem *)malloc(sizeof(*new))))
		return (NULL);
	new->nb = n;
	new->next = NULL;
	return (new);
}

void		ft_push(t_stack *pile, int n)
{
	t_elem	*new;

	new = ft_create_elem(n);
	if (new->nb > pile->max)
		pile->max = new->nb;
	if (new->nb < pile->min)
		pile->min = new->nb;
	pile->size = pile->size + 1;
	if (pile->first)
		new->next = pile->first;
	pile->first = new;
}
