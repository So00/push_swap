/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:18:03 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 17:18:31 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_end_a(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	while (b->len)
	{
		do_move(pa, a, b, move);
		do_move(ra, a, b, move);
	}
}

void		ft_solve_three(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	if (b->ar[0] < b->ar[1] && b->ar[1] > b->ar[2] && b->ar[0] < b->ar[2])
	{
		do_move(sb, a, b, move);
		do_move(rb, a, b, move);
	}
	else if (b->ar[0] > b->ar[1] && b->ar[1] < b->ar[2] && b->ar[0] < b->ar[2])
		do_move(sb, a, b, move);
	else if (b->ar[0] > b->ar[1] && b->ar[1] < b->ar[2] && b->ar[0] < b->ar[2])
		do_move(sb, a, b, move);
	else if (b->ar[0] > b->ar[1] && b->ar[1] < b->ar[2] && b->ar[0] > b->ar[2])
		do_move(rb, a, b, move);
	else
		do_move(rrb, a, b, move);
}

void		ft_sort_three(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	if (b->len == 2)
	{
		if (b->ar[1] < b->ar[0])
			do_move(sb, a, b, move);
	}
	else if (b->len == 3 && !is_list_sort(b->ar, b->len, 0))
	{
		if (is_list_sort(b->ar, b->len, 1))
		{
			do_move(sb, a, b, move);
			do_move(rrb, a, b, move);
		}
		else
			ft_solve_three(a, b, move);
	}
	if (b->len)
		push_end_a(a, b, move);
}
