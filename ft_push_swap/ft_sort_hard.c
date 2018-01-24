/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:27:25 by atourner          #+#    #+#             */
/*   Updated: 2018/01/24 07:19:11 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_b_sort(t_push_ar *b)
{
	int		i;

	if (b->min == b->max)
		return (1);
	i = 0;
	while (b->ar[i] != b->min && b->ar[i] != b->max)
		i++;
	if (b->ar[i] == b->min)
	{	
		if (i == 0)
			i = b->len - 1;
		while(b->ar[i - 1] > b->ar[i] &&
				b->ar[i - 1] <= b->max && b->ar[i] != b->max)
		{
			if (i == 1 && b->ar[0] > b->ar[1])
				i = b->len - 1;
			if (i == b->len - 1 && b->ar[0] > b->ar[i])
				return (0);
			i--;
		}
		if (b->ar[i] == b->max)
			return (1);
		return (0);
	}
	return (is_list_sort(b->ar, b->len, 1));
}

void	ft_search_low_med(t_push_ar *a, t_push_ar *b, int nb_srch,
		void (*move[11])())
{
	int		i;

	i = 0;
	while (a->ar[i] > nb_srch)
		i++;
	if (i < a->len / 2)
		while (a->ar[0] > nb_srch)
		{
			move[ra](&a->ar, &b->ar, &a->len, &b->len);
			what_print(ra);
		}
	else
		while (a->ar[0] > nb_srch)
		{
			move[rra](&a->ar, &b->ar, &a->len, &b->len);
			what_print(rra);
		}
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

int		ft_search(t_push_ar *to_chr, int nb_srch)
{
	int		i;

	i = 0;
	while (i < to_chr->len)
	{
		
	}
}

void	ft_fit_b(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		move_need;

	if (a->ar[0] > b->max || a->ar[0] < b->min)
	{
		move_need = ft_search(b, a->ar[0]);
		while ((b->ar[0] != b->max && a->ar[0] > max) || (b->ar[0] != b->min && a->ar[0] < min))
			move[move_need](&a->ar, &b->ar, &a->len, &b->len);
	}
}

void	ft_sort_hard(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		med;
	int		tmp;

	med = ft_get_med(a);
//	while (!is_list_sort(b->ar, b->len, 1) && a->len > b->len)
//	{
		ft_search_low_med(a, b, med, move);
		ft_fit_b(a, b, move);
		if (!is_list_sort(a->ar, a->len, 0))
		{
			move[pb](&a->ar, &b->ar, &a->len, &b->len);
			what_print(pb);
		}
//	}
	/*while (b->len)
	{
		move[pa](&a->ar, &b->ar, &a->len, &b->len);
		what_print(pa);
	}*/
}
