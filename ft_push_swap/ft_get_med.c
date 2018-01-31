/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_med.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:00:11 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 13:10:25 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_insert(int *ar, int nb_add, int start)
{
	while (--start != -1)
	{
		if (start != 0 && ar[start] > nb_add && ar[start - 1] > nb_add)
			ar[start + 1] = ar[start];
		else
		{
			ar[start + 1] = ar[start];
			ar[start] = nb_add;
			break ;
		}
	}
}

int			ft_get_med(t_push_ar *a)
{
	int		*sort_ar;
	int		i;

	if (!(sort_ar = (int*)ft_strnew(sizeof(int) * a->len)))
		return (-1);
	i = 0;
	while (i != a->len)
	{
		if (i == 0)
			sort_ar[i] = a->ar[i];
		else
		{
			if (a->ar[i] > sort_ar[i - 1])
				sort_ar[i] = a->ar[i];
			else
				ft_insert(sort_ar, a->ar[i], i);
		}
		i++;
	}
	i = sort_ar[(a->len / 2) - (a->len % 2 ? 0 : 1)];
	free(sort_ar);
	return (i);
}

int			ft_get_highest(t_push_ar *a)
{
	int		*sort_ar;
	int		i;

	if (!(sort_ar = (int*)ft_strnew(sizeof(int) * a->len)))
		return (-1);
	i = 0;
	while (i != a->len)
	{
		if (i == 0)
			sort_ar[i] = a->ar[i];
		else
		{
			if (a->ar[i] > sort_ar[i - 1])
				sort_ar[i] = a->ar[i];
			else
				ft_insert(sort_ar, a->ar[i], i);
		}
		i++;
	}
	i = sort_ar[a->len - 3];
	free(sort_ar);
	return (i);
}

int		ft_get_min(t_push_ar *a, int len)
{
	int		i;
	int		min;

	i = -1;
	while (++i < len)
		if (i == 0 || a->ar[i] < min)
			min = a->ar[i];
	return (min);
}
