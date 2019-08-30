/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:30:22 by dberger           #+#    #+#             */
/*   Updated: 2019/08/30 12:22:59 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void		ft_clean_stack(t_stack *a, t_stack *b)
{
	while (a->first)
		ft_del_elem(a);
	while (b->first)
		ft_del_elem(b);
	free(a);
	free(b);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || !ft_check_arg(argv))
		write(2, "Error\n", 6);
	else if (!(a = ft_init_a(argc, argv)))
		write(2, "Error\n", 6);
	else if (!(b = ft_create_stack()))
		write(2, "Error\n", 6);
	else if (!(ft_instruct(a, b)))
		write(2, "Error\n", 6);
	else if (!(ft_stack_order(a, b)))
		ft_printf("		{red}KO\n\n");
	else
		ft_printf("		{green}OK\n\n");
	if (a && b)
		ft_clean_stack(a, b);
	return (0);
}
