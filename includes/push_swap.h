/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:53:43 by dberger           #+#    #+#             */
/*   Updated: 2019/09/02 18:42:58 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define SHOW 0 

typedef struct		s_elem
{
	int				nb;
	int				rank;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_stack
{
	int				size;
	int				op;
	int				min;
	int				max1;
	int				max2;
	int				max3;
	struct s_elem	*first;
	struct s_elem	*last;
}					t_stack;

typedef struct		s_instr
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_instr;

int					ft_check_arg(char **argv);
t_stack				*ft_create_stack(void);
void				ft_print_instr(t_stack *a, t_stack *b,
					char *str, int color);
void				ft_push(t_stack *pile, int n);
void				ft_swap(t_stack *pile);
int					ft_rotate(t_stack *pile, int mode);
int					ft_del_elem(t_stack *pile);
int					ft_instruct(t_stack *a, t_stack *b);
int					ft_stack_order(t_stack *a, t_stack *b);
void				ft_count_instr(t_stack *a, t_stack *b,
					t_instr *list, t_elem *tmp);
t_instr				*ft_choose_nb(t_stack *a, t_stack *b, t_instr *good, t_instr *compare);
int					ft_arrange_b(t_stack *a, t_stack *b, int argc);
int					ft_finish_swap(t_stack *a, t_stack *b);

#endif
