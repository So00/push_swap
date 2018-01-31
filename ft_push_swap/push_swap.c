/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:20 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 16:30:40 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_list_sort(int *act, int len, int descending)
{
	int		i;

	i = -1;
	if (descending)
	{
		while (++i < len)
			if (act[i] < act[i + 1])
				return (0);
		return (1);
	}
	while (++i < len)
		if (act[i] > act[i + 1])
			return (0);
	return (1);
}

int				order_in_rev(int *act, int len)
{
	int		stop_asc;

	stop_asc = 0;
	while (stop_asc < len - 1 && act[stop_asc] < act[stop_asc + 1])
		stop_asc++;
	while (act[len] > act[len - 1])
		len--;
	if (stop_asc == len - 1 || stop_asc == len)
		return (1);
	return (0);
}

static void		solve(t_push_ar *a, t_push_ar *b, void (*move[11])())
{
	int		tmp;
	int		med;

	if (order_in_rev(a->ar, a->len - 1))
		ft_sort_easy(a, b, move);
	else if (a->len <= 6)
		ft_sort_bubble(a, b, move);
	else
		ft_sort_hard(a, b, move);
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
			free(a.ar);
		else if (!is_list_sort(a.ar, a.len, 0))
		{
			solve(&a, &b, move);
			free(a.ar);
			free(b.ar);
		}
		else
			ft_printf("\n");
	}
	return (0);
}
