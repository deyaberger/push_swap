/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:19:48 by dberger           #+#    #+#             */
/*   Updated: 2019/09/05 14:27:04 by dberger          ###   ########.fr       */
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
	char	 **arg;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	arg = ft_strsplit(argv[1], 32);
	while(arg[i])
		i++;
	argc = i;
	if (!ft_check_arg(arg))
		write(2, "Error\n", 6);
	else if (!(a = ft_init_a(argc, arg)))
		write(2, "Error\n", 6);
	else if (!(b = ft_create_stack()))
		write(2, "Error\n", 6);
	else if (!(ft_instruct(a, b)))
		write(2, "Error\n", 6);
	else if (!(ft_stack_order(a, b)))
		ft_printf("		{red}KO{eoc} \n\n");
	else
		ft_printf("		{green}OK{eoc} \n\n");
	ft_print_instr(a, b, "", 5);
	if (a && b)
		ft_clean_stack(a, b);
	return (0);
}
