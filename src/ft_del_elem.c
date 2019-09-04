/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:06:32 by dberger           #+#    #+#             */
/*   Updated: 2019/09/04 13:56:43 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
