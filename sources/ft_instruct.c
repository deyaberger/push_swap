/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:47 by dberger           #+#    #+#             */
/*   Updated: 2019/08/13 15:09:09 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_read_swap(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(a);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		return (0);
	return (1);
}

int		ft_read_push(char *line, t_stack *a, t_stack *b)
{
	int		n;

	if (!ft_strcmp(line, "pa") && b->first)
	{
		n = ft_del_elem(b);
		ft_push(a, n);
	}
	else if (!ft_strcmp(line, "pb") && a->first)
	{
		n = ft_del_elem(a);
		ft_push(b, n);
	}
	else
		return (0);
	return (1);
}

int		ft_read_rot(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "ra"))
		ft_rotate(a, 1);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(b, 1);
	else if (!ft_strcmp(line, "rr"))
	{
		ft_rotate(a, 1);
		ft_rotate(b, 1);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_rotate(a, 2);
	else if (!ft_strcmp(line, "rrb"))
		ft_rotate(b, 2);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_rotate(a, 2);
		ft_rotate(b, 2);
	}
	else
		return (0);
	return (1);
}

int		ft_instruct(t_stack *a, t_stack *b)
{
	int		fd;
	char	*line;

	fd = 0;
	ft_printf("\na = \n");
	ft_list_print(a, 1);
	ft_printf("b = \n");
	ft_list_print(b, 1);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != 's' && line[0] != 'p' && line[0] != 'r')
			return (0);
		else if (line[0] == 's' && !ft_read_swap(line, a, b))
			return (0);
		else if (line[0] == 'p' && !ft_read_push(line, a, b))
			return (0);
		else if (line[0] == 'r' && !ft_read_rot(line, a, b))
			return (0);
		ft_printf("		*****\n");
		ft_printf("\na = \n");
		ft_list_print(a, 1);
		ft_printf("b = \n");
		ft_list_print(b, 1);
		ft_printf("		*****\n");
		free(line);
	}
	return (1);
}