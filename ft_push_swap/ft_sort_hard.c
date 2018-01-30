/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:27:25 by atourner          #+#    #+#             */
/*   Updated: 2018/01/30 14:17:45 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_search_low_med(t_push_ar *a, t_push_ar *b, int nb_srch,
		void (*move[11])())
{
	int		i;

	i = 0;
	while (a->ar[i] > nb_srch)
		i++;
	if (i < a->len / 2)
		while (a->ar[0] > nb_srch)
			do_move(ra, a, b, move);
	else
		while (a->ar[0] > nb_srch)
			do_move(rra, a, b, move);
	if (!b->len)
	{
		b->min = a->ar[0];
		b->max = a->ar[0];
	}
	else
	{
		if (b->min > a->ar[0])
			b->min = a->ar[0];
		if (b->max < a->ar[0])
			b->max = a->ar[0];
	}
}



void	ft_sort_hard(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		med;
	int		tmp;

	med = ft_get_med(a);
	ft_printf("%d\n", med);
}
