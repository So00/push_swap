/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:18:03 by atourner          #+#    #+#             */
/*   Updated: 2018/02/01 10:49:29 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_to_sort(t_push_ar *a, int next_med)
{
	int		i;

	i = 0;
	while (a->ar[i] != next_med)
		i++;
	return (i);
}

void		push_end_a(t_push_ar *a, t_push_ar *b, void (*move[11])(),
		int next_med)
{
	int bug = 0;
	if (!b->len)
		while (a->ar[0] != next_med && ++bug < 10)
			do_move(ra, a, b, move);
	else
	{
		while (a->ar[0] != next_med)
		{
			if (!b->len || a->ar[0] < b->ar[0])
				do_move(ra, a, b, move);
			else
			{
				do_move(pa, a, b, move);
				do_move(ra, a, b, move);
			}
		}
		if (b->len)
		{
			do_move(pa, a, b, move);
			do_move(ra, a, b, move);
		}
	}
}

void		ft_solve_three(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	if (a->ar[0] < a->ar[1] && a->ar[1] > a->ar[2] && a->ar[0] < a->ar[2])
	{
		do_move(ra, a, b, move);
		do_move(sa, a, b, move);
	}
	else if (a->ar[0] > a->ar[1] && a->ar[1] < a->ar[2] && a->ar[0] < a->ar[2])
		do_move(sa, a, b, move);
	else if (a->ar[0] > a->ar[1] && a->ar[1] < a->ar[2] && a->ar[0] > a->ar[2])
		do_move(pb, a, b, move);
	else
	{
		do_move(pb, a, b, move);
		do_move(sa, a, b, move);
	}
}

void		ft_sort_three(t_push_ar *a, t_push_ar *b, void (*move[11])(),
		int next_med)
{
	int		len;

	len = len_to_sort(a, next_med);
	if (len == 2)
	{
		if (a->ar[1] < a->ar[0])
			do_move(sa, a, b, move);
	}
	else if (len == 3 && !is_list_sort(a->ar, len, 0))
	{
		if (is_list_sort(a->ar, len, 1))
		{
			do_move(pb, a, b, move);
			do_move(sa, a, b, move);
		}
		else
			ft_solve_three(a, b, move);
	}
	push_end_a(a, b, move, next_med);
}
