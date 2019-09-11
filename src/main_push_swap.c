/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:33:37 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 15:52:50 by dberger          ###   ########.fr       */
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

void		ft_clean_stack(t_stack *a, t_stack *b)
{
	while (a->first)
		ft_del_elem(a);
	while (b->first)
		ft_del_elem(b);
	free(a);
	free(b);
}

int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	int		mode;

	a = NULL;
	b = NULL;
	mode = SHOW;
	if (argc == 1)
		return (1);
	if (!ft_check_arg(argv))
		if (ft_error())
			return (0);
	a = ft_init_a(argc, argv);
	b = ft_create_stack();
	if (!a || !b)
		if (ft_error())
			return (0);
	if (mode == 3)
		ft_print_instr(a, b, "", 1);
	if (argc > 3)
		if (!(ft_arrange_b(a, b)))
			if (ft_error())
			{	
				ft_clean_stack(a, b);
				return (0);
			}
	if (argc > 2)
		ft_finish_swap(a, b);
	if (mode == 3)
		ft_print_instr(a, b, "", 3);
	ft_clean_stack(a, b);
	return (1);
}

__attribute__((destructor)) void test()
{
	while (1);
}
