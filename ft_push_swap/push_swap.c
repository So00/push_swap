/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:20 by atourner          #+#    #+#             */
/*   Updated: 2018/03/06 13:12:15 by atourner         ###   ########.fr       */
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
	int		tmp;

	stop_asc = 0;
	tmp = len;
	while (stop_asc < len - 1 && act[stop_asc] < act[stop_asc + 1])
		stop_asc++;
	while (act[tmp] > act[tmp - 1])
		tmp--;
	if (stop_asc == tmp - 1 && (act[len] < act[0] || act[len - 1] > act[len]))
		return (1);
	return (0);
}

static void		solve(t_push_ar *a, t_push_ar *b)
{
	if ((order_in_rev(a->ar, a->len - 1)
				&& a->ar[0] > a->ar[a->len - 1]) || a->len == 3)
		ft_sort_easy(a, b);
	else if (a->len <= 6)
		ft_sort_bubble(a, b);
	else
		ft_sort_hard(a, b);
}

int				main(int ac, char **av)
{
	t_push_ar	a;
	t_push_ar	b;

	b.len = 0;
	if (ac == 1 || !(a.len = ft_get_push_ar(ac, av, &a.ar)))
		ft_printf("Error\n");
	else
	{
		b.ar = (int*)malloc(sizeof(int) * a.len);
		if (b.ar && !is_list_sort(a.ar, a.len, 0))
			solve(&a, &b);
		else
			ft_printf("\n");
		free(a.ar);
		if (b.ar)
			free(b.ar);
	}
	return (0);
}
