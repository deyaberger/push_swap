/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:53:43 by dberger           #+#    #+#             */
/*   Updated: 2019/08/12 12:01:29 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_stack
{
	int				size;
	int				min;
	int				max;
	struct s_elem	*first;
}					t_stack;

int					ft_check_arg(char **argv);
t_stack				*ft_create_stack(void);
void				ft_list_print(t_stack *list);
void				ft_push(t_stack *pile, int n);
void				ft_swap(t_stack *pile);
int					ft_rotate(t_stack *pile, int mode);
int					ft_del_elem(t_stack *pile);
int					ft_instruct(t_stack *a, t_stack *b);
int					ft_stack_order(t_stack *a, t_stack *b);

#endif
