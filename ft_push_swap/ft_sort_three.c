/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:18:03 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 20:07:22 by atourner         ###   ########.fr       */
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
	int		bug;

	bug = 0;
	if (!b->len)
		while (a->ar[0] != next_med && ++bug < 10)
			do_move(ra, a, b, move);
	else
	{
		while ((a->ar[0] != next_med || b->len) && bug < 10)
		{
			if (!b->len || a->ar[0] < b->ar[0])
				do_move(ra, a, b, move);
			else
			{
				do_move(pa, a, b, move);
				do_move(ra, a, b, move);
			}
			++bug;
		}
	}
	if (bug == 10)
	{
		ft_printf("blen %d alen %d next_med %d\n", b->len, a->len, next_med);
		for (int i = 0; i < a->len; i++)
			ft_printf("a %d\n", a->ar[i]);
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
	else if (b->ar[0] > b->ar[1] && b->ar[1] < b->ar[2] && b->ar[0] > b->ar[2])
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
	ft_printf("%d %d \n",next_med, a->len);
	for (int i = 0; i < a->len; i++)
		ft_printf("a %d  i %d\n", a->ar[i], i);
}
