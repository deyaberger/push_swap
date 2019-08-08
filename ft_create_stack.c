/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:30:23 by dberger           #+#    #+#             */
/*   Updated: 2019/08/08 16:40:38 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_create_stack(void)
{
	t_stack	*pile;

	if (!(pile = (t_stack *)malloc(sizeof(*pile))))
		return (NULL);
	pile->size = 0;
	pile->first = NULL;
	return (pile);
}
