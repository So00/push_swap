/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:27:25 by atourner          #+#    #+#             */
/*   Updated: 2018/02/16 09:45:24 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_still_med(t_push_ar *act, int med, int superior)
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

static void	push_med_a(t_push_ar *a, t_push_ar *b, int med[2])
{
	int		choose_way;

	choose_way = ft_choose_way(b, med[0]);
	while (is_still_med(b, med[0], 1))
		if (b->ar[0] >= med[0])
		{
			do_move(PA, a, b);
			choose_way = ft_choose_way(b, med[0]);
		}
		else if (b->ar[0] == med[1])
		{
			do_move(PA, a, b);
			if (choose_way == RB && b->ar[0] < med[0])
				do_move(RR, a, b);
			else
				do_move(RA, a, b);
			med[1] = ft_get_min(b, b->len);
		}
		else
			do_move(choose_way, a, b);
}

static void	push_med_b(t_push_ar *a, t_push_ar *b, int med, int next_med)
{
	while (is_still_med(a, med, 0))
	{
		if (a->ar[0] <= med)
			do_move(PB, a, b);
		else if (b->ar[0] < next_med)
			do_move(RR, a, b);
		else
			do_move(RA, a, b);
	}
}

void		ft_len(t_push_ar *a, t_push_ar *b, int *all_med)
{
	int		med[2];

	med[0] = ft_get_med(b, NULL);
	med[1] = ft_get_min(b, b->len);
	push_med_a(a, b, med);
	if (a->ar[a->len - 1] != med[0])
	{
		all_med[0]++;
		all_med[all_med[0]] = a->ar[0];
	}
}

void		ft_sort_hard(t_push_ar *a, t_push_ar *b)
{
	int		med;
	int		*all_med;
	int		next_med;

	all_med = (int*)ft_strnew(sizeof(int) * a->len);
	med = ft_get_med(a, &next_med);
	push_med_b(a, b, med, next_med);
	all_med[1] = a->ar[a->len - 1];
	all_med[2] = a->ar[0];
	all_med[0] = 2;
	while (b->len > 3)
		ft_len(a, b, all_med);
	while (a->ar[0] != all_med[2] || b->len)
		ft_sort_three(a, b, all_med);
	ft_push_in_b(a, b, ft_get_min(a, a->len));
	all_med[2] = a->ar[0];
	while (b->len > 3)
		ft_len(a, b, all_med);
	while (a->ar[0] != all_med[2])
		ft_sort_three(a, b, all_med);
}
