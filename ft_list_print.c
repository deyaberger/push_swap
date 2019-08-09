/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:43:55 by dberger           #+#    #+#             */
/*   Updated: 2019/08/09 15:45:58 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_list_print(t_stack *list)
{
	t_elem	*link;

	link = list->first;
	while (link)
	{
		ft_printf("	%d\n", link->nb);
		link = link->next;
	}
	link = list->first;
}
