/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:20 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 03:17:37 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int		order_in_rev(int *act, int *len)
{
	int		stop_asc;

	stop_asc = -1;
	while (++stop_asc < *len - 1 && act[stop_asc] < act[stop_asc + 1])
		;
	while (++stop_asc > *len - 1 && act[stop_asc] < act[stop_asc])
		;
	if (stop_asc == *len - 1)
		return (1);
	return (0);
}

static void		solve(int *a, int *b, int a_len, void (*move[11])())
{
	int		b_len;

	b_len = 0;
	while (b_len || !is_list_sort(a, a_len, 0))
	{
		printf("%d\n", order_in_rev(a, a_len));
		move[ra](&a,&b,&a_len,&b_len);
	}
}

int				main(int ac, char **av)
{
	int		*a;
	int		*b;
	int		a_len;
	void	(*move[11])(int **, int **, int *, int *);

	ft_initialize_function(void (*apply_move[11])());
	if (ac == 1 || !(a_len = ft_get_push_ar(ac, av, &a)))
		ft_printf("Error\n");
	else
	{
		if (!(b = (int*)malloc(sizeof(int) * a_len)))
			return (free_all(a, NULL, NULL));
		ft_solve(a, b, a_len, move);
	}
	return (0);
}
