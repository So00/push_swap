/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:20 by atourner          #+#    #+#             */
/*   Updated: 2018/01/23 17:05:53 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_list_sort(int *act, int len, int descending)
{
	int		i;

	i = -1;
	if (descending)
	{
		while (++i < len - 1)
			if (act[i] < act[i + 1])
				return (0);
		return (1);
	}
	while (++i < len - 1)
		if (act[i] > act[i + 1])
			return (0);
	return (1);
}

int				order_in_rev(int *act, int len)
{
	int		stop_asc;

	stop_asc = -1;
	while (++stop_asc < len - 1 && act[stop_asc] < act[stop_asc + 1])
		;
	while (++stop_asc < len - 1 && act[stop_asc] < act[stop_asc + 1])
		;
	if (stop_asc == len - 1)
		return (1);
	return (0);
}

static void		solve(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		tmp;
	int		med;

	if (b->len || !is_list_sort(a->ar, a->len, 0))
	{
		if (!b->len && order_in_rev(a->ar, a->len))
			ft_sort_easy(a, b, move);
	}
}

int				main(int ac, char **av)
{
	int		*get_tab;
	void	(*move[11])(int **, int **, int *, int *);
	t_push_ar	a;
	t_push_ar	b;

	b.len = 0;
	ft_initialize_function(move);
	if (ac == 1 || !(a.len = ft_get_push_ar(ac, av, &a.ar)))
		ft_printf("Error\n");
	else
	{
		if (!(b.ar = (int*)malloc(sizeof(int) * a.len)))
		{
			free(a.ar);
			return (0);
		}
		solve(&a, &b, move);
	}
	return (0);
}
