/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:33:37 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:36:24 by dberger          ###   ########.fr       */
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

int			ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void		ft_finish_main(t_stack *a, t_stack *b, int argc)
{
	int		mode;

	mode = SHOW;
	if (argc > 2)
		ft_finish_swap(a, b);
	if (mode == 3)
		ft_print_instr(a, b, "", 3);
	ft_clean_stack(a, b);
}

/*
** Just like in the main of checker, we check if the arguments are correct,
** then we create two stacks: B will be empty and A will contain the numbers
** listed as arguments. 
** In ft_arrange, we will choose what instruction should be sent to the standard
** entry, and change the stack accordingly to it. Once everything is arranged,
** we want to make sure everything we have created has been freed correctly.
*/

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (!ft_check_arg(argv))
		if (ft_error())
			return (0);
	a = ft_init_a(argc, argv);
	if (!a || !(b = ft_create_stack()))
		if (ft_error())
			return (0);
	if (SHOW == 3)
		ft_print_instr(a, b, "", 1);
	if (argc > 3)
		if (!(ft_arrange_b(a, b)))
			if (ft_error())
			{
				ft_clean_stack(a, b);
				return (0);
			}
	ft_finish_main(a, b, argc);
	return (1);
}

/*
** __attribute__((destructor)) void test()
** {
** 	while (1);
** }
*/
