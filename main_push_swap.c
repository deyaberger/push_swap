/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:30:22 by dberger           #+#    #+#             */
/*   Updated: 2019/08/30 16:15:26 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack		*ft_init_a(int argc, char **argv)
{
	t_stack *a;
	int		i;

	if (!(a = ft_create_stack()))
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		ft_push(a, ft_atoi(argv[i]));
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
	ft_printf("\n");
	if (argc == 1 || !ft_check_arg(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (!(a = ft_init_a(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (!(b = ft_create_stack()))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_print_instr(a, b, "", 1);
	if (argc > 2 && !(ft_arrange_b(a, b, argc)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc > 2)
		ft_finish_swap(a, b);
	ft_print_instr(a, b, "", 3);
	ft_printf("\nTotal of operations = %d\n\n", a->op);
	return (0);
}
