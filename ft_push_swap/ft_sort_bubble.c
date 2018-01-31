/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:43:13 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 10:15:21 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_bubble(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		min;
	int		min_b;
	int		done;

	done = 0;
	while (b->len || !is_list_sort(a->ar, a->len, 0))
	{
		if (done <= a->len)
			min = ft_get_min(a, a->len - done);
		if (b->len)
			min_b = ft_get_min(b, b->len);
		if (min < min_b && done < a->len && a->ar[a->len - 1] != min)
		{
			while (a->ar[0] != min)
				do_move(pb, a, b, move);
			do_move(ra, a, b, move);
		}
		else if (b->len && (min > min_b || done >= a->len))
		{
			while (b->ar[0] != min_b)
				do_move(rb, a, b, move);
			do_move(pa, a, b, move);
			do_move(ra, a, b, move);
		}
		done++;
	}
}
