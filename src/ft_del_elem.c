/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:06:32 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 17:11:20 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** To be able to clean a stack or do the operations "pa" or "pb" we need to
** first delete a element of the stack concerned, saved the number that was
** included in the structure, to then created a new element with this number
** and at it to the top of the other stack for example.
*/

int		ft_del_elem(t_stack *pile)
{
	t_elem	*del;
	int		n;

	del = pile->first;
	n = del->nb;
	pile->first = del->next;
	pile->size = pile->size - 1;
	free(del);
	return (n);
}
