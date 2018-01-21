# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 01:31:15 by atourner          #+#    #+#              #
#    Updated: 2018/01/21 03:17:32 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap

NAME_CHECK = checker

FLAGS = -Wall -Werror -Wextra

LIB = ft_printf/libftprintf.a

INCLUDES = ft_printf/includes

SRC_CHECKER = \
		initialize_and_get_arg/ft_get_push_ar.c\
		initialize_and_get_arg/ft_initialize_function.c\
		move/move_push.c\
		move/move_reverse_rotate.c\
		move/move_rotate.c\
		move/move_swap.c\
		checker/checker.c\
		checker/ft_is_list_sort.c

SRC_PUSHSWAP = \
		initialize_and_get_arg/ft_get_push_ar.c\
		initialize_and_get_arg/ft_initialize_function.c\
		move/move_push.c\
		move/move_reverse_rotate.c\
		move/move_rotate.c\
		move/move_swap.c\
		push_swap/push_swap.c

COMP_CHECKER = $(SRC_CHECKER:.c=.o)

COMP_PUSHSWAP = $(SRC_PUSHSWAP:.c=.o)

all : $(NAME_PUSH) $(NAME_CHECK)

%.o:%.c
	gcc $(FLAGS) -o $@ -c $< -I$(INCLUDES)

$(NAME_CHECK) : $(COMP_CHECKER)
	make -C ft_printf
	gcc $(FLAGS) $(COMP_CHECKER) $(LIB) -o $(NAME_CHECK)

$(NAME_PUSH) : $(COMP_PUSHSWAP)
	make -C ft_printf
	gcc $(FLAGS) $(COMP_PUSHSWAP) $(LIB) -o $(NAME_PUSH)

clean :
	make clean -C ft_printf
	rm -rf $(COMP_CHECKER) $(COMP_PUSHSWAP)

fclean : clean
	make fclean -C ft_printf
	rm -rf $(NAME_CHECK) $(NAME_PUSH)
