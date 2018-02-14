/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:18:03 by atourner          #+#    #+#             */
/*   Updated: 2018/02/12 16:07:28 by atourner         ###   ########.fr       */
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

void		push_end_a(t_push_ar *a, t_push_ar *b,
		int next_med)
{
	if (!b->len)
		while (a->ar[0] != next_med)
			do_move(RA, a, b);
	else
	{
		while (a->ar[0] != next_med)
		{
			if (!b->len || a->ar[0] < b->ar[0])
				do_move(RA, a, b);
			else
			{
				do_move(PA, a, b);
				do_move(RA, a, b);
			}
		}
		if (b->len)
		{
			do_move(PA, a, b);
			do_move(RA, a, b);
		}
	}
}

void		ft_solve_three(t_push_ar *a, t_push_ar *b)
{
	if (a->ar[0] < a->ar[1] && a->ar[1] > a->ar[2] && a->ar[0] < a->ar[2])
	{
		do_move(RA, a, b);
		do_move(SA, a, b);
	}
	else if (a->ar[0] > a->ar[1] && a->ar[1] < a->ar[2] && a->ar[0] < a->ar[2])
		do_move(SA, a, b);
	else if (a->ar[0] > a->ar[1] && a->ar[1] < a->ar[2] && a->ar[0] > a->ar[2])
		do_move(PB, a, b);
	else
	{
		do_move(PB, a, b);
		do_move(SA, a, b);
	}
}

void		ft_sort_three(t_push_ar *a, t_push_ar *b,
		int next_med)
{
	int		len;

	len = len_to_sort(a, next_med);
	if (len == 2)
	{
		if (a->ar[1] < a->ar[0])
			do_move(SA, a, b);
	}
	else if (len == 3 && !is_list_sort(a->ar, len, 0))
	{
		if (is_list_sort(a->ar, len, 1))
		{
			do_move(PB, a, b);
			do_move(SA, a, b);
		}
		else
			ft_solve_three(a, b);
	}
	push_end_a(a, b, next_med);
}
