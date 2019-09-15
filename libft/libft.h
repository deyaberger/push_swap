/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:42:42 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 16:00:52 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strrev(char *str);
long				ft_sizenb(int n);
long				ft_sizenb_l(long n);
unsigned long		ft_sizenb_u(unsigned long n);
long				ft_strlen_l(const char *s);

#endif
