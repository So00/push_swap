/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:35:11 by atourner          #+#    #+#             */
/*   Updated: 2018/02/02 22:49:07 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		a_list(int move_to_do, t_push_ar *a, t_push_ar *b,
		void (*move[11])())
{
	if (move_to_do == pa)
	{
		ft_printf("pa\n");
		move[pa](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == sa)
	{
		ft_printf("sa\n");
		move[sa](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == ra)
	{
		ft_printf("ra\n");
		move[ra](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == rra)
	{
		ft_printf("rra\n");
		move[rra](&a->ar, &b->ar, &a->len, &b->len);
	}
}

void		b_list(int move_to_do, t_push_ar *a, t_push_ar *b,
		void (*move[11])())
{
	if (move_to_do == pb)
	{
		ft_printf("pb\n");
		move[pb](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == sb)
	{
		ft_printf("sb\n");
		move[sb](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == rb)
	{
		ft_printf("rb\n");
		move[rb](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == rrb)
	{
		ft_printf("rrb\n");
		move[rrb](&a->ar, &b->ar, &a->len, &b->len);
	}
}

void		both_list(int move_to_do, t_push_ar *a, t_push_ar *b,
		void (*move[11])())
{
	if (move_to_do == ss)
	{
		ft_printf("ss\n");
		move[ss](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == rr)
	{
		ft_printf("rr\n");
		move[rr](&a->ar, &b->ar, &a->len, &b->len);
	}
	else if (move_to_do == rrr)
	{
		ft_printf("rrr\n");
		move[rrr](&a->ar, &b->ar, &a->len, &b->len);
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
