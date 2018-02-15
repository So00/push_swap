/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:43:13 by atourner          #+#    #+#             */
/*   Updated: 2018/02/15 15:58:12 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_b(t_push_ar *a, t_push_ar *b)
{
	if (b->len == 3)
	{
		if (b->ar[1] > b->ar[0] && b->ar[1] > b->ar[2])
			do_move(SB, a, b);
		else if (b->ar[2] > b->ar[0] && b->ar[2] > b->ar[1])
			do_move(RRB, a, b);
		do_move(PA, a, b);
	}
	if (b->ar[0] < b->ar[1])
		do_move(SB, a, b);
	while (b->len)
		do_move(PA, a, b);
}

void		sort_a(t_push_ar *a, t_push_ar *b)
{
	if (a->len == 3)
	{
		if (a->ar[1] > a->ar[0] && a->ar[1] > a->ar[2] && a->ar[1] > a->ar[2])
			do_move(SA, a, b);
		if (a->ar[0] > a->ar[2] && a->ar[0] > a->ar[1])
			do_move(RA, a, b);
	}
	if (a->ar[0] > a->ar[1])
		do_move(SA, a, b);
}

void		ft_sort_bubble(t_push_ar *a, t_push_ar *b)
{
	int		med;

	med = ft_get_med(a, NULL);
	while (is_still_med(a, med, 0))
		if (a->ar[0] <= med)
			do_move(PB, a, b);
		else
			do_move(RA, a, b);
	if (!is_list_sort(a->ar, a->len, 0) && a->len > 1)
		sort_a(a, b);
	sort_b(a, b);
}
