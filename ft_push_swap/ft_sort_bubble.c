/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:43:13 by atourner          #+#    #+#             */
/*   Updated: 2018/02/02 22:23:38 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_b(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	if (b->len == 3)
	{
		if (b->ar[1] > b->ar[0] && b->ar[1] > b->ar[2])
			do_move(sb, a, b, move);
		else if (b->ar[2] > b->ar[0] && b->ar[2] > b->ar[1])
			do_move(rrb, a, b, move);
		do_move(pa, a, b, move);
	}
	if (b->ar[0] < b->ar[1])
		do_move(sb, a, b, move);
	while (b->len)
		do_move(pa, a, b, move);
}

void		sort_a(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	if (a->len == 3)
	{
		if (a->ar[1] > a->ar[0] && a->ar[1] > a->ar[2] && a->ar[1] > a->ar[2])
			do_move(sa, a, b, move);
		if (a->ar[0] > a->ar[2] && a->ar[0] > a->ar[1])
			do_move(ra, a, b, move);
	}
	if (a->ar[0] > a->ar[1])
		do_move(sa, a, b, move);
}

void		ft_sort_bubble(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		med;

	med = ft_get_med(a);
	while (is_still_med(a, med, 0))
		if (a->ar[0] <= med)
			do_move(pb, a, b, move);
		else
			do_move(ra, a, b, move);
	if (!is_list_sort(a->ar, a->len, 0) && a->len > 1)
		sort_a(a, b, move);
	sort_b(a, b, move);
}
