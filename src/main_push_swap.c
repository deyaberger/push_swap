/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:33:37 by dberger           #+#    #+#             */
/*   Updated: 2019/09/04 16:23:39 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ft_init_a(int argc, char **arg)
{
	t_stack *a;
	int		i;

	if (!(a = ft_create_stack()))
		return (0);
	i = argc - 1;
	while (i >= 0)
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
	char	**arg;
	int 	i;

	a = NULL;
	b = NULL;
	i = 0;
	if(argc == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	arg = ft_strsplit(argv[1], ' ');
	while(arg[i])
		i++;
	argc = i;
	if (!ft_check_arg(arg))
	{
		write(2, "Error1\n", 7);
		return (0);
	}
	else if (!(a = ft_init_a(argc, arg)))
	{
		write(2, "Error2\n", 7);
		return (0);
	}
	else if (!(b = ft_create_stack()))
	{
		write(2, "Error3\n", 7);
		return (0);
	}
	if (argc > 2 && !(ft_arrange_b(a, b, argc)))
	{
		write(2, "Error4\n", 7);
		return (0);
	}
	if (argc > 2)
		ft_finish_swap(a, b);
//	ft_printf("\nTotal of operations = %d\n\n", a->op);
	return (0);
}
