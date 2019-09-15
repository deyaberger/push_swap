/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:47:44 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:08:14 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
