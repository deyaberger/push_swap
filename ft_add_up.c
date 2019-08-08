/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:53:12 by dberger           #+#    #+#             */
/*   Updated: 2019/08/08 17:56:09 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem		*ft_create_elem(int n)
{
	t_elem *new;

	if (!(new = (t_elem *)malloc(sizeof(*new))))
		return (NULL);
	new->nb = n;
	new->next = NULL;
	return (new);
}

void		ft_add_up(t_stack *pile, int n)
{
	t_elem	*new;

	new = ft_create_elem(n);
	if (!pile->first)
	{
		pile->first = new;
		pile->size = pile->size + 1;
	}
	else
	{
		new->next = pile->first;
		pile->first = new;
		pile->size = pile->size + 1;
	}
}
