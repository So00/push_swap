/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_easy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 04:41:20 by atourner          #+#    #+#             */
/*   Updated: 2018/01/23 17:44:38 by atourner         ###   ########.fr       */
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

void	push_first_sort_b(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	while (a->ar[0] < a->ar[1])
	{
		move[pb](&a->ar, &b->ar, &a->len, &b->len);
		what_print(pb);
	}
		move[pb](&a->ar, &b->ar, &a->len, &b->len);
		what_print(pb);
}

void	push_all_in_reverse(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	while (a->ar[0] > a->ar[a->len - 1])
	{
		move[rra](&a->ar, &b->ar, &a->len, &b->len);
		what_print(rra);
	}
}

void	ft_fill_a(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	while (b->len)
	{
		while (a->ar[a->len - 1] > b->ar[0])
		{
			move[rra](&a->ar, &b->ar, &a->len, &b->len);
			what_print(rra);
		}
		move[pa](&a->ar, &b->ar, &a->len, &b->len);
		what_print(pa);
	}
}

void	ft_sort_easy(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		tmp;

	if (!is_list_sort(a->ar, a->len, 0))
	{
		if (a->ar[0] > a->ar[a->len - 1])
			push_all_in_reverse(a, b, move);
		if (!b->len && order_in_rev(a->ar, a->len))
			push_first_sort_b(a, b, move);
		if (b->len)
		{
			ft_fill_a(a, b, move);
			push_all_in_reverse(a, b, move);
		}
	}
	for (int i = 0; i < a->len; i++)
		ft_printf("tab[%d] = %d\n",i, a->ar[i]);
}
