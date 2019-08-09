/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:47 by dberger           #+#    #+#             */
/*   Updated: 2019/08/09 16:25:26 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_read_swap(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(a);
	if (!ft_strcmp(line, "sb"))
		ft_swap(b);
	if (!ft_strcmp(line, "ss"))
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_read_push(char *line, t_stack *a, t_stack *b)
{
	int		n;

	if (!ft_strcmp(line, "pa") && b->first)
	{
		n = ft_del_elem(b);
		ft_push(a, n);
	}
	if (!ft_strcmp(line, "pb") && a->first)
	{
		n = ft_del_elem(a);
		ft_push(b, n);
	}
}

void	ft_read_rot(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "ra"))
		ft_rotate(a, 1);
	if (!ft_strcmp(line, "rb"))
		ft_rotate(b, 1);
	if (!ft_strcmp(line, "rr"))
	{
		ft_rotate(a, 1);
		ft_rotate(b, 1);
	}
	if (!ft_strcmp(line, "rra"))
		ft_rotate(a, 2);
	if (!ft_strcmp(line, "rrb"))
		ft_rotate(b, 2);
	if (!ft_strcmp(line, "rrr"))
	{
		ft_rotate(a, 2);
		ft_rotate(b, 2);
	}
}

int		ft_instruct(t_stack *a, t_stack *b)
{
	int		fd;
	char	*line;

	fd = 0;
	ft_printf("a = \n");
	ft_list_print(a);
	ft_printf("b = \n");
	ft_list_print(b);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
			&& ft_strcmp(line, "ss") && ft_strcmp(line, "pa")
			&& ft_strcmp(line, "pb") && ft_strcmp(line, "ra")
			&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr")
			&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
			&& ft_strcmp(line, "rrr"))
			return (0);
		if (line[0] == 's')
			ft_read_swap(line, a, b);
		if (line[0] == 'p')
			ft_read_push(line, a, b);
		if (line[0] == 'r')
			ft_read_rot(line, a, b);
		ft_printf("a = \n");
		ft_list_print(a);
		ft_printf("b = \n");
		ft_list_print(b);
		free(line);
	}
	return (1);
}
