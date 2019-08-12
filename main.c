/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:30:22 by dberger           #+#    #+#             */
/*   Updated: 2019/08/12 13:36:05 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc == 1 || !ft_check_arg(argv))
		write (2, "Error\n", 6);
	if (!(a = ft_init_a(argc, argv)))
		write (2, "Error\n", 6);
	if (!(b = ft_create_stack()))
		write (2, "Error\n", 6);
	else
		ft_printf("OK\n");
	if (!(ft_instruct(a, b)))
		write (2, "Error\n", 6);
	if (!(ft_stack_order(a, b)))
		write (2, "Error dans ordre\n", 17);
	else
		write (2, "OK\n", 3);
	return (0);
}
