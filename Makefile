# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 12:00:30 by dberger           #+#    #+#              #
#    Updated: 2019/09/12 17:15:27 by dberger          ###   ########.fr        #
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
HFILE = ./includes/push_swap.h

LIB_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
DIR_OBJ = ./objects

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
	 src/ft_do_instruct.c \
	 src/ft_swap.c \
	 src/get_next_line.c

PUSH_SRC = src/main_push_swap.c
PUSH_SRC += $(SRC)
PUSH_OBJ = $(patsubst src/%.c,$(DIR_OBJ)/%.o,$(PUSH_SRC))

CHECK_SRC = src/main_checker.c
CHECK_SRC += $(SRC)
CHECK_OBJ = $(patsubst src/%.c,$(DIR_OBJ)/%.o,$(CHECK_SRC))

LIB = $(FT_PRINTF_DIR)/$(PTF) \
	  $(LIB_DIR)/$(LIBF)

.PHONY: all clean fclean re norme

all: $(PUSH_NAME) $(CHECKER_NAME)

$(LIB): FORCE
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf

$(PUSH_NAME): $(LIB) $(PUSH_OBJ)
	@$(CC) -o $(PUSH_NAME) $(PUSH_OBJ) $(LIB)
	@echo "$(YELLOW)	--- $(GREEN)Push_Swap$(YELLOW) Compiled ! ---	$(NO_COLOR)"

$(CHECKER_NAME): $(LIB) $(CHECK_OBJ)
	@$(CC) -o $(CHECKER_NAME) $(CHECK_OBJ) $(LIB)
	@echo "$(YELLOW)	--- $(GREEN)Checker$(YELLOW) Compiled ! ---	$(NO_COLOR)"

$(DIR_OBJ)/%.o:src/%.c $(H_FILE)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@rm -rf $(LIB)
	@rm -rf $(DIR_OBJ)/$(PUSH_OBJ)
	@rm -rf $(DIR_OBJ)/main_push_swap.o
	@rm -rf $(DIR_OBJ)/$(CHECK_OBJ)
	@rm -rf $(DIR_OBJ)/main_checker.o
	@echo "$(BLUE)	--- Binary deleted ! ---	$(NO_COLOR)"

fclean: clean
	@rm -rf $(PUSH_NAME)
	@rm -rf $(CHECKER_NAME)
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@(cd $(FT_PRINTF_DIR) && $(MAKE) $@)
	@echo "$(PINK)	--- Programm deleted ! ---	$(NO_COLOR)"

re: fclean all

FORCE:
