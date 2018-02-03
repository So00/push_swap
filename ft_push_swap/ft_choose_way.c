/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 23:45:16 by atourner          #+#    #+#             */
/*   Updated: 2018/02/03 01:34:52 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_choose_way(t_push_ar *a, int med, int add)
{
	int		i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->ar[i] >= med)
			return (i <= a->len / 2 ? ra + add : rra + add);
		i++;
	}
	return (rra + add);
}

void	ft_push_in_b(t_push_ar *a, t_push_ar *b, int med)
{
	int		min;
	int		len;

	len = -1;
	while (b->ar[0] != med && a->ar[a->len - 1] != med)
	{
		if (len < 0)
		{
			while (a->ar[++len] != med)
				;
			min = ft_get_min(a, a->len);
		}
		if (a->ar[0] == min)
		{
			do_move(ra, a, b);
			len = -1;
		}
		else
			do_move(pb, a, b);
	}
}
