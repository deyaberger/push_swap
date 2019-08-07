/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:53:43 by dberger           #+#    #+#             */
/*   Updated: 2019/08/07 16:29:14 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct 		s_stack
{
	int 			nb;
	struct s_stack *next;
}					t_stack;

int					ft_check_arg(char **argv); 

#endif
