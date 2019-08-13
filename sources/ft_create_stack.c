/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:30:23 by dberger           #+#    #+#             */
/*   Updated: 2019/08/13 15:08:48 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ft_create_stack(void)
{
	t_stack	*pile;

	if (!(pile = (t_stack *)malloc(sizeof(*pile))))
		return (NULL);
	pile->size = 0;
	pile->min = 2147483647;
	pile->max = -2147483648;
	pile->first = NULL;
	return (pile);
}
