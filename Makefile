# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 12:00:30 by dberger           #+#    #+#              #
#    Updated: 2019/09/04 13:36:39 by dberger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
YELLOW = \033[33m
GREEN = \033[32m
BLUE = \033[36m
PINK = \033[35m

PUSH_NAME = push_swap
CHECKER_NAME = checker
PTF = libftprintf.a
LIBF= libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf

SRC = src/ft_arrange_b.c \
	 src/ft_check_arg.c \
	 src/ft_choose_nb.c \
	 src/ft_count_instr.c \
	 src/ft_create_stack.c \
	 src/ft_del_elem.c \
	 src/ft_finish_swap.c \
	 src/ft_instruct.c \
	 src/ft_print_instr.c \
	 src/ft_push.c \
	 src/ft_rotate.c \
	 src/ft_stack_order.c \
	 src/ft_swap.c \
	 gnl/get_next_line.c \

PUSH_SRC = src/main_push_swap.c \

CHECK_SRC = src/main_checker.c \

.PHONY: all clean fclean re norme

$(PUSH_NAME):
	@(cd $(LIB_DIR) && $(MAKE))
	@cp $(LIB_DIR)/libft.a ./libft.a
	@(cd $(FT_PRINTF_DIR) && $(MAKE))
	@cp $(FT_PRINTF_DIR)/libftprintf.a ./libftprintf.a
	@$(CC) -o $(PUSH_NAME) $(SRC) $(PUSH_SRC) $(PTF) $(LIBF)
	@echo "$(YELLOW)	--- $(GREEN)Push_Swap$(YELLOW) Compiled ! ---	$(NO_COLOR)"
	@$(CC) -o $(CHECKER_NAME) $(SRC) $(CHECK_SRC) $(PTF) $(LIBF)
	@echo "$(YELLOW)	--- $(GREEN)Checker$(YELLOW) Compiled ! ---	$(NO_COLOR)"

all: $(PUSH_NAME)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@rm -Rf $(LIBF) $(PTF)
	@echo "$(BLUE)	--- Binary deleted ! ---	$(NO_COLOR)"

fclean: clean
	@rm -rf $(PUSH_NAME)
	@rm -rf $(CHECKER_NAME)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@echo "$(PINK)	--- Programm deleted ! ---	$(NO_COLOR)"

re: fclean all
