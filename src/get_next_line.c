/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:47:44 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:15:40 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** We read caracter per caracter, add then one by one directly in *line,
** When we encounter a "\n" we get out of the function and analyzes it in
** ft_instruct, if there is more than 4 caracters in the instruction, we know
** it is an error and we return (-1). This "adapted gnl" helps us read an
** instruction that would contain a "\0" for example.
*/

int			ft_content(int fd, char **line)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while ((ret = read(fd, *line + i, 1)))
	{
		if ((*line)[i] == '\n')
			return (1);
		i++;
		if (i > 3)
			return (-1);
	}
	if (ret == 0 && i == 0)
		ft_memdel((void**)line);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int r_v;

	r_v = -1;
	if (fd >= 0 && line)
		if ((*line = ft_memalloc(5)))
			if (read(fd, NULL, 0) != -1)
				r_v = ft_content(fd, line);
	return (r_v);
}
