/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:00:19 by dberger           #+#    #+#             */
/*   Updated: 2019/08/08 17:56:43 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *pile)
{
	int		i;
	int		j;
	t_elem	*start;

	start = pile->first;
	i = start->nb;
	j = start->next->nb;
	start->nb = j;
	start->next->nb = i;
}
