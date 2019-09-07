/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:33:37 by dberger           #+#    #+#             */
/*   Updated: 2019/09/07 13:19:16 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ft_init_a(int argc, char **arg)
{
	t_stack *a;
	int		i;

	if (!(a = ft_create_stack()))
		return (NULL);
	i = argc - 1;
	while (i > 0)
	{
		ft_push(a, ft_atoi(arg[i]));
		i--;
	}
	return (a);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (!ft_check_arg(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a = ft_init_a(argc, argv);
	b = ft_create_stack();
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_print_instr(a, b, "", 1);
	if (argc > 3)
		if (!(ft_arrange_b(a, b)))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	if (argc > 2)
		ft_finish_swap(a, b);
	ft_print_instr(a, b, "", 3);
	return (1);
}
