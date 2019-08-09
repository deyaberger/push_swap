/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:47 by dberger           #+#    #+#             */
/*   Updated: 2019/08/09 15:35:15 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_read_swap(char *line, t_stack *a, t_stack *b)
{
	if ((line[1] != 'a' && line[1] != 'b' && line[1] != 's')
			|| (line[2] != '\n' && line[2] != '\0'))
		return (0);
	if (line[1] == 'a')
		ft_swap(a);
	if (line[1] == 'b')
		ft_swap(b);
	if (line[1] == 's')
	{
		ft_swap(a);
		ft_swap(b);
	}
	return (1);
}

int		ft_read_push(char *line, t_stack *a, t_stack *b)
{
	int		n;

	if ((line[1] != 'a' && line[1] != 'b')
			|| (line[2] != '\n' && line[2] != '\0'))
		return (0);
	if (line[1] == 'a' && b->first)
	{
		n = ft_del_elem(b);
		
		ft_push(a, n);
	}
	if (line[1] == 'b' && a->first)
	{
		n = ft_del_elem(a);
		ft_push(b, n);
	}
	return (1);
}

int		ft_read_rot(char *line, t_stack *a, t_stack *b)
{
	if (line[1] != 'a' && line[1] != 'b' && line[1] != 'r')
		return (0);
	if ((line[1] == 'a' || line[1] == 'b') && line[2])
		return (0);
	if (line[1] == 'a')
		ft_rotate(a, 1);
	if (line[1] == 'b')
		ft_rotate(b, 1);
	if (line[1] == 'r' && !line[2])
	{
		ft_rotate(a, 1);
		ft_rotate(b, 1);
	}
	if ((line[1] == 'r' && line[2] && line[3])
		|| (line[1] == 'r' && line[2] && line[2] != 'a'
		&& line[2] != 'b' && line[2] != 'r'))
		return (0);
	if (line[1] == 'r' && line[2] == 'a')
		ft_rotate(a, 2);
	if (line[1] == 'r' && line[2] == 'b')
		ft_rotate(b, 2);
	if (line[1] == 'r' && line[2] == 'r')
	{
		ft_rotate(a, 2);
		ft_rotate(b, 2);
	}
	return (1);
}

int		ft_instruct(t_stack *a, t_stack *b)
{
	int 	fd;
	char 	*line;

	fd = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != 's' && line[0] != 'p' && line[0] != 'r')
			return (0);
		if (line[0] == 's')
			if (!line[1] || !(ft_read_swap(line, a, b)))
				return (0);
		if (line[0] == 'p')
			if (!line[1] || !(ft_read_push(line, a, b)))
				return (0);
		if (line[0] == 'r')
			if (!line[1] || !(ft_read_rot(line, a, b)))
				return (0);
		free (line);
	}
	return (1);
}
