/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_instruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:45:19 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 17:13:19 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This function is used in push_swap and checker, it receives a valid
** instruction, included in the char *str, then applies it to one of the
** functions created for rotation or swaping. For example, "ra" is a rotation
** of the pile a towards the top. It calles the mode 1 of ft_rotate for a
*/

void		ft_do_instruct(t_stack *a, t_stack *b, char *str, int i)
{
	int		mode;
	t_stack *pile;

	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n")
			|| !ft_strcmp(str, "rr\n") || !ft_strcmp(str, "1"))
		mode = 1;
	else
		mode = 2;
	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rra\n")
			|| !ft_strcmp(str, "1") || !ft_strcmp(str, "2"))
		pile = a;
	else
		pile = b;
	while (i)
	{
		if (!ft_strcmp(str, "sa\n"))
			ft_swap(a);
		else
			ft_rotate(pile, mode);
		if (ft_strcmp(str, "1") && ft_strcmp(str, "2"))
			ft_print_instr(a, b, str, 2);
		i--;
	}
}
