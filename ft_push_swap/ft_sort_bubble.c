/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:43:13 by atourner          #+#    #+#             */
/*   Updated: 2018/02/02 16:22:58 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_solve_first_case(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	if (a->ar[0] < a->ar[1] && a->ar[1] > a->ar[2] && a->ar[0] < a->ar[2])
	{
		do_move(rra, a, b, move);
		do_move(sa, a, b, move);
	}
	else if (a->ar[0] > a->ar[1] && a->ar[1] > a->ar[2])
	{
		do_move(sa, a, b, move);
		do_move(rra, a, b, move);
	}
}

void		fill_a(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		search_move;

	while (b->len || !is_list_sort(a->ar, a->len, 0))
	{
		search_move = 0;
		if (b->len && b->ar[0] > a->ar[a->len - 1])
		{
			do_move(pa, a, b, move);
			do_move(ra, a, b, move);
		}
		else if (b->len)
		{
			while (b->len && a->ar[search_move] < b->ar[0])
				search_move++;
			if (search_move <= a->len / 2)
				search_move = ra;
			else
				search_move = rra;
			while (b->ar[0] > a->ar[0] || b->ar[0] < a->ar[a->len - 1])
				do_move(search_move, a, b, move);
			do_move(pa, a, b, move);
		}
		else
		{
			while (a->ar[search_move] < a->ar[search_move + 1])
				search_move++;
			if (search_move < a->len / 2)
				search_move = ra;
			else
				search_move = rra;
			while (!is_list_sort(a->ar, a->len, 0))
				do_move(search_move, a, b, move);
		}
	}
}

void		ft_sort_bubble(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	while (a->len > 3)
		do_move(pb, a, b, move);
	if (b->len && !is_list_sort(b->ar, b->len, 1))
		do_move(rb, a, b, move);
	if (a->len < 3)
	{
		if (a->len == 2 && a->ar[0] > a->ar[1])
			do_move(rra, a, b, move);
	}
	else if (a->ar[0] < a->ar[1] && a->ar[1] > a->ar[2] && a->ar[0] < a->ar[2])
		ft_solve_first_case(a, b, move);
	else if (a->ar[0] > a->ar[1] && a->ar[1] < a->ar[2] && a->ar[0] < a->ar[2])
		do_move(sa, a, b, move);
	else if (a->ar[0] > a->ar[1] && a->ar[1] < a->ar[2] && a->ar[0] > a->ar[2])
		do_move(ra, a, b, move);
	else if (a->ar[0] > a->ar[1] && a->ar[1] > a->ar[2])
		ft_solve_first_case(a, b, move);
	else
		do_move(rra, a, b, move);
	fill_a(a, b, move);
}
