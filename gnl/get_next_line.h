/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:45:54 by dberger           #+#    #+#             */
/*   Updated: 2019/09/10 16:08:43 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# define BUFF_SZ 32

typedef	struct	s_fd
{
	char	*tab;
	int		fd;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
