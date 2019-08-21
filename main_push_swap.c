/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:30:22 by dberger           #+#    #+#             */
/*   Updated: 2019/08/21 14:28:43 by dberger          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || !ft_check_arg(argv))
		write (2, "Error\n", 6);
	else if (!(a = ft_init_a(argc, argv)))
		write (2, "Error\n", 6);
	else if (!(b = ft_create_stack()))
		write (2, "Error\n", 6);
	ft_printf("a =\n");
	ft_list_print(a, 1);
	ft_printf("b =\n");
	ft_list_print(b, 1);
	ft_printf("a->size = %d\n", a->size);
	ft_printf("a->min = %d\n", a->min);
	ft_printf("a->max3 = %d\n", a->max3);
	ft_printf("a->max2 = %d\n", a->max2);
	ft_printf("a->max = %d\n\n", a->max);
	ft_send_instruct(a, b);
	return (0);
}
