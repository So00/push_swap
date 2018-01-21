/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_easy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 04:41:20 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 09:52:23 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	what_print(int print)
{
	if (!print)
		ft_printf("pa\n");
	else if (print == 1)
		ft_printf("sa\n");
	else if (print == 2)
		ft_printf("ra\n");
	else if (print == 3)
		ft_printf("rra\n");
	else if (print == 4)
		ft_printf("rr\n");
	else if (print == 5)
		ft_printf("ss\n");
	else if (print == 6)
		ft_printf("rrr\n");
	else if (print == 7)
		ft_printf("rrb\n");
	else if (print == 8)
		ft_printf("rb\n");
	else if (print == 9)
		ft_printf("sb\n");
	else
		ft_printf("pb\n");
}

int		search_closest(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		len;
	int		len_end;

	len = -1;
	while (++len < a->len - 1 && a->ar[len] < a->ar[len + 1])
		;
	if (len < a->len / 2 && a->ar[len] > a->ar[a->len - 1])
		return (ra);
	if (len > a->len/2 && a->ar[len] > a->ar[a->len - 1])
		return (rra);
	len_end = 1;
	while (a->ar[a->len - len_end] > a->ar[len])
		len_end++;
	if (len >= len_end)
	{
		while (len_end--)
		{
			move[rra](&a->ar, &b->ar, &a->len, &b->len);
			what_print(rra);
		}
		while (a->ar[len_end - 1] > a->ar[len])
		{
			move[pa](&a->ar, &b->ar, &a->len, &b->len);
			what_print(pb);
		}
	}
	return (rra);
}

int		ft_sort_easy(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		tmp;

	if (!is_list_sort(a->ar, a->len, 0))
	{
		move[(tmp = search_closest(a, b, move))](&a->ar, &b->ar, &a->len, &b->len);
		what_print(tmp);
	}
	for (int i = 0; i < a->len; i++)
		ft_printf("tab[%d] = %d\n",i, a->ar[i]);
	return (1);
}
