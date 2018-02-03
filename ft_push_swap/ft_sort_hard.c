/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:27:25 by atourner          #+#    #+#             */
/*   Updated: 2018/02/03 01:34:50 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_still_med(t_push_ar *act, int med, int superior)
{
	int		i;

	i = 0;
	while (i < act->len)
	{
		if (!superior && act->ar[i] <= med)
			return (1);
		if (superior && act->ar[i] >= med)
			return (1);
		i++;
	}
	return (0);
}

void	push_med_a(t_push_ar *a, t_push_ar *b, int med[2])
{
	int		choose_way;

	choose_way = ft_choose_way(b, med[0], 6);
	while (is_still_med(b, med[0], 1))
		if (b->ar[0] >= med[0])
		{
			do_move(pa, a, b);
			choose_way = ft_choose_way(b, med[0], 6);
		}
		else if (b->ar[0] == med[1])
		{
			do_move(pa, a, b);
			if (choose_way == rb && b->ar[0] < med[0])
				do_move(rr, a, b);
			else
				do_move(ra, a, b);
			med[1] = ft_get_min(b, b->len);
		}
		else
			do_move(rb, a, b);
}

void	push_med_b(t_push_ar *a, t_push_ar *b, int med)
{
	while (is_still_med(a, med, 0))
	{
		if (a->ar[0] <= med)
			do_move(pb, a, b);
		else
			do_move(ra, a, b);
	}
}

void	ft_len(t_push_ar *a, t_push_ar *b, int all_med[a->len])
{
	int		med[2];

	med[0] = ft_get_highest(b);
	med[1] = ft_get_min(b, b->len);
	push_med_a(a, b, med);
	if (a->ar[a->len - 1] != med[0])
	{
		all_med[0]++;
		all_med[all_med[0]] = a->ar[0];
	}
}

void	ft_sort_hard(t_push_ar *a, t_push_ar *b)
{
	int		med;
	int		all_med[a->len];

	ft_bzero(all_med, sizeof(int) * a->len);
	med = ft_get_med(a);
	push_med_b(a, b, med);
	all_med[1] = a->ar[a->len - 1];
	all_med[2] = a->ar[0];
	all_med[0] = 2;
	while (b->len)
		ft_len(a, b, all_med);
	while (a->ar[0] != all_med[2])
		ft_sort_three(a, b, all_med[--all_med[0]]);
	ft_push_in_b(a, b, all_med[1]);
	all_med[2] = a->ar[0];
	while (b->len)
		ft_len(a, b, all_med);
	while (a->ar[0] != all_med[2])
		ft_sort_three(a, b, all_med[--all_med[0]]);
}
