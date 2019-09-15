# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 10:16:12 by dberger           #+#    #+#              #
#    Updated: 2019/09/15 16:04:06 by dberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
YELLOW = \033[33m
GREEN = \033[32m
BLUE = \033[36m
PINK = \033[35m

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES = ft_bzero.c\
ft_strlen.c\
ft_strrev.c\
ft_strcmp.c\
ft_strncmp.c\
ft_atoi.c\
ft_isdigit.c\
ft_memalloc.c\
ft_memdel.c\
ft_sizenb.c\
ft_sizenb_l.c\
ft_sizenb_u.c\
ft_strlen_l.c

HEADER = libft.h
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) Makefile $(HEADER)
	@$(CC) $(FLAGS) -c $(SOURCES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)


%.o:src/%.c $(H_FILE)
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
