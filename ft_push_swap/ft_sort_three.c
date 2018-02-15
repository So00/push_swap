/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:18:03 by atourner          #+#    #+#             */
/*   Updated: 2018/02/15 14:11:15 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_end_a(t_push_ar *a, t_push_ar *b,
		int next_med)
{
	while (a->ar[0] != next_med)
	{
		if (!b->len || (b->len && a->ar[0] < b->ar[0]))
			do_move(RA, a, b);
		else
		{
			do_move(PA, a, b);
			do_move(RA, a, b);
		}
	}
	if (b->len)
		while (b->len)
		{
			do_move(PA, a, b);
			do_move(RA, a, b);
		}
}

void		ft_solve_three(t_push_ar *a, t_push_ar *b)
{
	if (b->ar[0] < b->ar[1] && b->ar[1] > b->ar[2] && b->ar[0] < b->ar[2])
	{
		do_move(PA, a, b);
		do_move(RR, a, b);
	}
	else if (b->ar[0] > b->ar[1] && b->ar[1] < b->ar[2] && b->ar[0] < b->ar[2])
		do_move(PA, a, b);
	else if (b->ar[0] > b->ar[1] && b->ar[1] < b->ar[2] && b->ar[0] > b->ar[2])
		do_move(PA, a, b);
	else if (b->ar[1] > b->ar[2] && b->ar[1] < b->ar[0])
	{
		do_move(PA, a, b);
		do_move(SB, a, b);
	}
	else
		do_move(RRB, a, b);
}

void		ft_sort_three(t_push_ar *a, t_push_ar *b,
		int *all_med)
{
	if (!b->len)
		ft_push_in_b(a, b, all_med[--all_med[0]]);
	if (b->len > 3)
		while (b->len > 3)
			ft_len(a, b, all_med);
	if (b->len < 3)
		do_move(PA, a, b);
	else if (!is_list_sort(b->ar, b->len, 0))
		ft_solve_three(a, b);
	push_end_a(a, b, all_med[all_med[0]]);
}
