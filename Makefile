# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 01:31:15 by atourner          #+#    #+#              #
#    Updated: 2018/02/12 15:57:12 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap

NAME_CHECK = checker


LIB = ft_printf/libftprintf.a

INCLUDES = ft_printf/includes

SRC_CHECKER = \
		initialize_and_get_arg/ft_get_push_ar.c\
		initialize_and_get_arg/ft_initialize_function.c\
		move/move_push.c\
		move/move_reverse_rotate.c\
		move/move_rotate.c\
		move/move_swap.c\
		ft_checker/checker.c\
		ft_checker/ft_is_sort_checker.c

SRC_PUSHSWAP = \
		initialize_and_get_arg/ft_get_push_ar.c\
		initialize_and_get_arg/ft_initialize_function.c\
		move/move_push.c\
		move/move_reverse_rotate.c\
		move/move_rotate.c\
		move/move_swap.c\
		ft_push_swap/push_swap.c\
		ft_push_swap/ft_sort_easy.c\
		ft_push_swap/ft_sort_hard.c\
		ft_push_swap/ft_get_med.c\
		move/ft_do_move.c\
		ft_push_swap/ft_sort_bubble.c\
		ft_push_swap/ft_sort_three.c\
		ft_push_swap/ft_choose_way.c\

COMP_CHECKER = $(SRC_CHECKER:.c=.o)

COMP_PUSHSWAP = $(SRC_PUSHSWAP:.c=.o)

all : LIB $(NAME_PUSH) $(NAME_CHECK)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(INCLUDES)

LIB :
	@make -C ft_printf

$(NAME_CHECK) : $(COMP_CHECKER)
	@echo "\033[0;35mCompilation Checker\033[0m"
	@gcc $(FLAGS) $(COMP_CHECKER) $(LIB) -o $(NAME_CHECK)

$(NAME_PUSH) : $(COMP_PUSHSWAP)
	@echo "\033[0;35mCompilation Push_swap\033[0m"
	@gcc $(FLAGS) $(COMP_PUSHSWAP) $(LIB) -o $(NAME_PUSH)

clean :
	@make clean -C ft_printf
	@rm -rf $(COMP_CHECKER) $(COMP_PUSHSWAP)

fclean : clean
	@make fclean -C ft_printf
	@rm -rf $(NAME_CHECK) $(NAME_PUSH)

re : fclean all
