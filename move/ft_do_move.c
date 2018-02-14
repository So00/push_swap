/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:35:11 by atourner          #+#    #+#             */
/*   Updated: 2018/02/12 15:00:16 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		a_list(int move_to_do, t_push_ar *a, t_push_ar *b,
		void (*move[11])())
{
	if (move_to_do == PA)
	{
		ft_printf("pa\n");
		move[PA](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == SA)
	{
		ft_printf("sa\n");
		move[SA](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == RA)
	{
		ft_printf("ra\n");
		move[RA](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == RRA)
	{
		ft_printf("rra\n");
		move[RRA](&a->ar, &b->ar, &a->len, &b->len);
	}
}

void		b_list(int move_to_do, t_push_ar *a, t_push_ar *b,
		void (*move[11])())
{
	if (move_to_do == PB)
	{
		ft_printf("pb\n");
		move[PB](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == SB)
	{
		ft_printf("sb\n");
		move[SB](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == RB)
	{
		ft_printf("rb\n");
		move[RB](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == RRB)
	{
		ft_printf("rrb\n");
		move[RRB](&a->ar, &b->ar, &a->len, &b->len);
	}
}

void		both_list(int move_to_do, t_push_ar *a, t_push_ar *b,
		void (*move[11])())
{
	if (move_to_do == SS)
	{
		ft_printf("ss\n");
		move[SS](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == RR)
	{
		ft_printf("rr\n");
		move[RR](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == RRR)
	{
		ft_printf("rrr\n");
		move[RRR](&a->ar, &b->ar, &a->len, &b->len);
	}
}

void		do_move(int move_to_do, t_push_ar *a, t_push_ar *b)
{
	void	(*move[11])(int **a, int **b, int *a_len, int *b_len);

	ft_initialize_function(move);
	if (move_to_do >= 0 && move_to_do <= 3)
		a_list(move_to_do, a, b, move);
	else if (move_to_do >= 7 && move_to_do <= 10)
		b_list(move_to_do, a, b, move);
	else
		both_list(move_to_do, a, b, move);
}
