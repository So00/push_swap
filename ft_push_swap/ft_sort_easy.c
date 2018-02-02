/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_easy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 04:41:20 by atourner          #+#    #+#             */
/*   Updated: 2018/02/02 20:18:24 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_search_stop_asc(t_push_ar *a)
{
	int		search;

	search = 0;
	while (a->ar[search] < a->ar[search + 1])
		search++;
	return (search);
}

int		ft_cmp(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

void	ft_sort_easy(t_push_ar *a, t_push_ar *b)
{
	int		stop_asc;

	stop_asc = ft_search_stop_asc(a);
	if (a->len <= 3)
	{
		if (a->len == 3 && a->ar[1] > a->ar[0] && a->ar[1] > a->ar[2]
				&& a->ar[0] < a->ar[2])
			do_move(sa, a, b);
		if (a->len == 3 && a->ar[0] < a->ar[1] && a->ar[1] > a->ar[2]
				&& a->ar[0] > a->ar[2])
			do_move(rra, a, b);
		if (a->ar[0] > a->ar[a->len - 1])
			do_move(ra, a, b);
		if (a->ar[0] > a->ar[1])
			do_move(sa, a, b);
	}
	if (stop_asc > a->len - stop_asc - 2)
		while (!is_list_sort(a->ar, a->len, 0))
			do_move(rra, a, b);
	else
		while (!is_list_sort(a->ar, a->len, 0))
			do_move(ra, a, b);
}
