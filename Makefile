# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 19:03:50 by ncoursol          #+#    #+#              #
#    Updated: 2019/08/13 15:14:21 by dberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
COMP_COLOR = \033[33m
BIN_COLOR = \033[32m
BIN2_COLOR = \033[36m
PROG_COLOR = \033[35m

NAME = checker
LIB_NAME = libft.a
PRINTF_NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
PRINTF_DIR = ./ft_printf

SOURCES = sources/ft_check_arg.c\
sources/ft_create_stack.c\
sources/ft_del_elem.c\
sources/ft_instruct.c\
sources/ft_list_print.c\
sources/ft_push.c\
sources/ft_rotate.c\
sources/ft_stack_order.c\
sources/ft_swap.c\
sources/main.c\
gnl/get_next_line.c\

INCLUDE = includes/push_swap.h

.PHONY: all clean fclean re norme

$(NAME):
	@(cd $(LIB_DIR) && $(MAKE))
	@(cd $(PRINTF_DIR) && $(MAKE))
	@$(CC) -o $(NAME) $(FLAGS) $(SOURCES) $(LIB_DIR)/$(LIB_NAME) $(PRINTF_DIR)/$(PRINTF_NAME)
	@echo "$(COMP_COLOR)	--- Compiled ! ---	$(NO_COLOR)"

all: $(NAME)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(PRINTF_DIR) && $(MAKE) $@)
	@echo "$(BIN2_COLOR)	--- Binary deleted ! ---	$(NO_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(PRINTF_DIR) && $(MAKE) $@)
	@echo "$(PROG_COLOR)	--- Programm deleted ! ---	$(NO_COLOR)"

re: fclean all
