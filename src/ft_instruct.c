/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:47 by dberger           #+#    #+#             */
/*   Updated: 2019/09/11 16:02:05 by dberger          ###   ########.fr       */
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

	if (!ft_strcmp(line, "pa"))
	{
		if (b->first)
		{
			n = ft_del_elem(b);
			ft_push(a, n);
		}
	}
	else if (!ft_strcmp(line, "pb"))
	{
		if (a->first)
		{
			n = ft_del_elem(a);
			ft_push(b, n);
		}
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

int		ft_check_line(char *line, t_stack *a, t_stack *b)
{
	if (line[0] != 's' && line[0] != 'p' && line[0] != 'r')
	{
		free(line);
		return (0);
	}
	if (line[0] == 's' && !ft_read_swap(line, a, b))
	{
		free(line);
		return (0);
	}
	if (line[0] == 'p' && !ft_read_push(line, a, b))
	{
		free(line);
		return (0);
	}
	if (line[0] == 'r' && !ft_read_rot(line, a, b))
	{
		free(line);
		return (0);
	}
	return (1);
}

int		ft_instruct(t_stack *a, t_stack *b)
{
	char	*line;
	int		mode;

	mode = SHOW;
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_check_line(line, a, b))
			return (0);
		if (mode == 2)
			ft_print_instr(a, b, line, 4);
		if (mode == 1)
			ft_print_instr(a, b, line, 5);
		free(line);
	}
	return (1);
}
