/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:20:12 by dberger           #+#    #+#             */
/*   Updated: 2019/09/02 18:45:10 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_stack_a(t_stack *a, t_elem *elem, int mode, int color)
{
	if (color == 1)
		ft_printf("\n{cyan}stack a to begin:{eoc} ");
	if (color == 2 && mode == 1)
		ft_printf("\n{yellow}stack a:{eoc} ");
	if (color == 3)
		ft_printf("\n{green}stack a at the end:{eoc} ");
	if (a->size == 0)
		ft_printf("{red} NULL{eoc}\n");
	ft_printf("\n");
	while (elem)
	{
		if (color == 2)
			ft_printf("         %d\n", elem->nb);
		if (color == 1 || color == 3)
			ft_printf("		   %d\n", elem->nb);
		elem = elem->next;
	}
}

void		ft_stack_b(t_stack *b, t_elem *elem, int mode, int color)
{
	if (color == 1)
		ft_printf("\n{cyan}stack b to begin:{eoc} ");
	if (color == 2 && mode == 1)
		ft_printf("\n{yellow}stack b:{eoc} ");
	if (color == 3)
		ft_printf("\n{green}stack b at the end:{eoc} ");
	if (b->size == 0)
		ft_printf("{red} NULL{eoc}\n");
	ft_printf("\n");
	while (elem)
	{
		if (color == 2)
			ft_printf("         %d\n", elem->nb);
		if (color == 1 || color == 3)
			ft_printf("		   %d\n", elem->nb);
		elem = elem->next;
	}
}

void		ft_print_instr(t_stack *a, t_stack *b, char *str, int color)
{
	t_elem	*elem;
	int		mode;

	mode = SHOW;
	if (str[0])
	{
		write(0, str, ft_strlen(str));
		a->op = a->op + 1;
	}
	if (color == 5)
	{
		mode = 2;
		color = 2;
	}
	if (mode == 1 || (mode == 2 && !str[0]))
	{
		elem = a->first;
		ft_stack_a(a, elem, mode, color);
		elem = b->first;
		ft_stack_b(b, elem, mode, color);
	}
}
