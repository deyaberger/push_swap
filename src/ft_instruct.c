/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:47 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:07:29 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_read_swap(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_swap(a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_swap(b);
	else if (!ft_strcmp(line, "ss\n"))
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

	if (!ft_strcmp(line, "pa\n"))
	{
		if (b->first)
		{
			n = ft_del_elem(b);
			ft_push(a, n);
		}
	}
	else if (!ft_strcmp(line, "pb\n"))
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
	if (!ft_strcmp(line, "ra\n"))
		ft_rotate(a, 1);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate(b, 1);
	else if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotate(a, 1);
		ft_rotate(b, 1);
	}
	else if (!ft_strcmp(line, "rra\n"))
		ft_rotate(a, 2);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rotate(b, 2);
	else if (!ft_strcmp(line, "rrr\n"))
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
	int		ret;

	mode = SHOW;
	while ((ret = get_next_line(0, &line)) == 1)
	{
		if (!ft_check_line(line, a, b))
			return (0);
		if (mode == 2)
			ft_print_instr(a, b, line, 4);
		if (mode == 1)
			ft_print_instr(a, b, line, 5);
		free(line);
	}
	if (ret == 0 && line)
	{
		if (!ft_check_line(line, a, b))
			return (0);
		free(line);
	}
	if (ret == -1)
		free(line);
	return (ret == -1 ? 0 : 1);
}
