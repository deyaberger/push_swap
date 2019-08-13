/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:43:55 by dberger           #+#    #+#             */
/*   Updated: 2019/08/13 15:09:17 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_list_print(t_stack *list, int mode)
{
	t_elem	*link;

	link = list->first;
	while (link)
	{
		if (mode == 1)
			ft_printf("     %d\n", link->nb);
		else if (mode == 2)
			ft_printf("			%d\n", link->nb);
		link = link->next;
	}
	ft_printf("\n");
	link = list->first;
}
