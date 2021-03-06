/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:19:48 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:32:32 by dberger          ###   ########.fr       */
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

void		ft_finish_main(t_stack *a, t_stack *b)
{
	ft_print_instr(a, b, "", 3);
	if (!(ft_stack_order(a, b)))
		ft_printf("		{red}KO{eoc} \n");
	else
		ft_printf("		{green}OK{eoc} \n");
	ft_clean_stack(a, b);
}

/*
** In Checker, we first check if the arguments are correct.
** Then we create a stack "A" and put all those numbers in it
** in each link of the chained list). We also create an empty stack "B".
** Then we start reading those instructions and apply it to the stacks we have.
** Finally when the lecture is finished, we check if "A" is in the good order
** and if "B" is empty.
*/

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (!ft_check_arg(argv))
		if (ft_error())
			return (0);
	if (!(a = ft_init_a(argc, argv)))
		if (ft_error())
			return (0);
	if (!(b = ft_create_stack()))
		if (ft_error())
			return (0);
	ft_print_instr(a, b, "", 1);
	if (!(ft_instruct(a, b)))
		if (ft_error())
		{
			ft_clean_stack(a, b);
			return (0);
		}
	ft_finish_main(a, b);
	return (1);
}

/*
** __attribute__((destructor)) void test()
** {
**	while (1);
**  }
*/
