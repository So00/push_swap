/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 23:45:16 by atourner          #+#    #+#             */
/*   Updated: 2018/02/15 20:07:14 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_choose_way(t_push_ar *a, int med)
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

static int	re_init_value(t_push_ar *a, t_push_ar *b, int *min_b, int med)
{
	int		len;

	len = -1;
	while (a->ar[++len] != med)
		;
	if (b->len)
		*min_b = ft_get_min(b, b->len);
	else
		*min_b = ft_get_min(a, len) + 1;
	return (len);
}

void		ft_push_in_b(t_push_ar *a, t_push_ar *b, int med)
{
	int		min;
	int		len;
	int		min_b;
	int		next_med;

	next_med = get_next_med(a, med);
	len = -1;
	while (a->ar[0] != med)
	{
		if (len < 0)
		{
			len = re_init_value(a, b, &min_b, med);
			min = ft_get_min(a, len);
		}
		if (a->ar[0] == min && min < min_b)
		{
			if (b->ar[0] > next_med)
				do_move(RA, a, b);
			else
				do_move(RR, a, b);
			len = -1;
		}
		else
			do_move(PB, a, b);
	}
}
