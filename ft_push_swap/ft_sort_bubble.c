/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:43:13 by atourner          #+#    #+#             */
/*   Updated: 2018/02/01 19:51:02 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_value(t_push_ar *a, int *min, int *max)
{
	int		i;

	i = 0;
	while (i < a->len - 1)
	{
		if (i == 0)
		{
			*min = a->ar[i];
			*max = a->ar[i];
		}
		else
		{
			if (a->ar[i] < *min)
				*min = a->ar[i];
			if (a->ar[i] > *max)
				*max = a->ar[i];
		}
		i++;
	}
}

void		ft_sort_bubble(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		min;
	int		max;

	get_value(a, &min, &max);
}
