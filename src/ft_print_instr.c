/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:20:12 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:29:06 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Color 1 and 3 will be used by checker and push swap to print stacks at the
** beginning andd at the end of the process. Then 2 will be used by push_swap
** to print the stacks after each instruction chosen. Same for checker, with
** the number 5.
*/

void		ft_stack_a(t_stack *a, t_elem *elem, int mode, int color)
{
	if (color == 1)
		ft_printf("\n{cyan}stack a to begin:{eoc} ");
	if ((color == 2 && mode == 3) || color == 4)
		ft_printf("\n\n{yellow}stack a:{eoc} ");
	if (color == 3)
		ft_printf("\n{green}stack a at the end:{eoc} ");
	if ((color == 1 || color == 3) && a->size != 0)
		ft_printf("\n");
	if (a->size == 0 && ((mode == 1 && (color == 1 || color == 3))
	|| color == 4 || mode == 3 || (mode == 2 && (color == 1 || color == 3))))
		ft_printf("{red} NULL{eoc}\n");
	if ((mode == 1 && (color == 1 || color == 3)) || color == 4
	|| (mode == 3) || (mode == 2 && (color == 1 || color == 3)))
		ft_printf("\n");
	while (elem)
	{
		if (color == 4 || (mode == 3 && color == 2))
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
	if ((color == 2 && mode == 3) || color == 4)
		ft_printf("\n{yellow}stack b:{eoc} ");
	if (color == 3)
		ft_printf("\n{green}stack b at the end:{eoc} ");
	if ((color == 1 || color == 3) && b->size != 0)
		ft_printf("\n");
	if (b->size == 0 && ((mode == 1 && (color == 1 || color == 3))
	|| color == 4 || mode == 3 || (mode == 2 && (color == 1 || color == 3))))
		ft_printf("{red} NULL{eoc}\n");
	if ((mode == 1 && (color == 1 || color == 3)) || color == 4
	|| (mode == 3) || (mode == 2 && (color == 1 || color == 3)))
		ft_printf("\n");
	while (elem)
	{
		if (color == 4 || (mode == 3 && color == 2))
			ft_printf("         %d\n", elem->nb);
		if (color == 1 || color == 3)
			ft_printf("		   %d\n", elem->nb);
		elem = elem->next;
	}
	if ((mode == 2 && color == 4) || mode == 3)
		ft_printf("\n");
}

/*
** This function is completly optional. I have created 4 modes, that we can
** choose while changing the value of "SHOW" in push_swap.h
** if SHOW == 0, we don't print anything in checker, and in push_swap we only
** print the instructions. If SHOW == 1, checker is going to print the value of
** the stacks before and after reading instructions. If SHOW == 2, checker shows
** the value of the stacks before, during, and after reading instructions.
** Finally if SHOW == 3, it is used only when we run push_swap alone: if shows
** the value of the stacks at every steps and it is useful when I have to change
** something in my functions and I want to test if it works correctly.
*/

void		ft_print_instr(t_stack *a, t_stack *b, char *str, int color)
{
	t_elem	*elem;
	int		mode;

	mode = SHOW;
	if (str[0])
		write(1, str, ft_strlen(str));
	if (color == 5 && mode == 1)
		ft_printf("\n");
	if (mode != 0)
	{
		elem = a->first;
		ft_stack_a(a, elem, mode, color);
		elem = b->first;
		ft_stack_b(b, elem, mode, color);
	}
}
