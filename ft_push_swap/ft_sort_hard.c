/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:27:25 by atourner          #+#    #+#             */
/*   Updated: 2018/02/01 12:34:53 by atourner         ###   ########.fr       */
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

void	push_med_a(t_push_ar *a, t_push_ar *b, void (*move[11])(), int med[2])
{
	while (is_still_med(b, med[0], 1))
		if (b->ar[0] >= med[0])
			do_move(pa, a, b, move);
		else if (b->ar[0] == med[1])
		{
			do_move(pa, a, b, move);
			do_move(ra, a, b, move);
			med[1] = ft_get_min(b, b->len);
		}
		else
			do_move(rb, a, b, move);
}

void	push_med_b(t_push_ar *a, t_push_ar *b, void (*move[11])(), int med)
{
	while (is_still_med(a, med, 0))
		if (a->ar[0] <= med)
			do_move(pb, a, b, move);
		else
			do_move(ra, a, b, move);
}

void	ft_len(t_push_ar *a, t_push_ar *b, void (*move[11])(),
		int *all_med)
{
	int		med[2];

	med[0] = ft_get_highest(b);
	med[1] = ft_get_min(b, b->len);
	push_med_a(a, b, move, med);
	if (a->ar[a->len - 1] != med[0])
	{
		all_med[0]++;
		all_med[all_med[0]] = a->ar[0];
	}
}

void	ft_sort_hard(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		med;
	int		*all_med;

	if (!(all_med = (int*)malloc(sizeof(int) * a->len)))
			return ;
	ft_bzero(all_med, sizeof(int) * a->len);
	med = ft_get_med(a);
	push_med_b(a, b, move, med);
	all_med[1] = a->ar[a->len - 1];
	all_med[2] = a->ar[0];
	all_med[0] = 2;
	while (b->len)
		ft_len(a, b, move, all_med);
	while (a->ar[0] != all_med[2] && all_med[0])
		ft_sort_three(a, b, move, all_med[--all_med[0]]);
	while (b->ar[0] != all_med[1])
		do_move(pb, a, b, move);
	all_med[2] = a->ar[0];
	while (b->len)
		ft_len(a, b, move, all_med);
	while (a->ar[0] != all_med[2] && --all_med[0])
		ft_sort_three(a, b, move, all_med[all_med[0]]);
	free(all_med);
/*	for (int i = 0; i < a->len; i++)
		ft_printf("a %d\n", a->ar[i]);
	ft_printf("\n\n");*/
}
