/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:30:22 by dberger           #+#    #+#             */
/*   Updated: 2019/08/08 19:01:51 by dberger          ###   ########.fr       */
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
		ft_add_up(a, ft_atoi(argv[i]));
		i--;
	}
	return (a);
}

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_elem	*test;

	if (argc == 1 || !ft_check_arg(argv))
		write (2, "Error dans arg\n", 15);
	if (!(a = ft_init_a(argc, argv)))
		write (2, "Error dans a\n", 13);
	if (!(b = ft_create_stack()))
		write (2, "Error dans stack b\n", 17);
	else
		ft_printf("OK\n");
	test = a->first;
	while (test)
	{
		ft_printf("normal= %d\n", test->nb);
		test = test->next;
	}
	test = a->first;
	ft_swap(a);
	test = a->first;
	ft_printf ("\n");
	while (test)
	{
		ft_printf("swap= %d\n", test->nb);
		test = test->next;
	}
	a = ft_rotate(a, 1);
	test = a->first;
	ft_printf ("\n");
	while (test)
	{
		ft_printf("rotate up= %d\n", test->nb);
		test = test->next;
	}
	a = ft_rotate(a, 2);
	test = a->first;
	ft_printf ("\n");
	while (test)
	{
		ft_printf("rotate down= %d\n", test->nb);
		test = test->next;
	}
	return (0);
}
