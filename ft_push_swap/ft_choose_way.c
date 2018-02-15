/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 23:45:16 by atourner          #+#    #+#             */
/*   Updated: 2018/02/15 14:00:14 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_choose_way(t_push_ar *a, int med)
{
	int		i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->ar[i] >= med)
			return (i <= a->len / 2 ? RB : RRB);
		i++;
	}
	return (RRB);
}

void	ft_push_in_b(t_push_ar *a, t_push_ar *b, int med)
{
	int		min;
	int		len;
	int		min_b;

	len = -1;
	while (a->ar[0] != med)
	{
		if (len < 0)
		{
			while (a->ar[++len] != med)
				;
			min = ft_get_min(a, len);
			if (b->len)
				min_b = ft_get_min(b, b->len);
			else
				min_b = min + 1;
		}
		if (a->ar[0] == min && min < min_b)
		{
			do_move(RA, a, b);
			len = -1;
		}
		else
			do_move(PB, a, b);
	}
}
