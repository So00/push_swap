/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:21:11 by atourner          #+#    #+#             */
/*   Updated: 2018/02/15 20:08:33 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_end_test(int **a, int **b, int a_len, int b_len)
{
	int		ret;

	if (b_len)
	{
		free_all(a, b, NULL);
		return (0);
	}
	ret = -1;
	while (++ret < a_len - 1)
		if ((*a)[ret] > (*a)[ret + 1])
		{
			free_all(a, b, NULL);
			return (0);
		}
	free(*a);
	free(*b);
	return (1);
}

static int	ft_choose_move(char *str)
{
	static char	move[11][4] = {{"pa\0"}, {"sa\0"}, {"ra\0"}, {"rra\0"},
		{"rr\0"}, {"ss\0"}, {"rrr\0"}, {"rrb\0"}, {"rb\0"}, {"sb\0"}, {"pb\0"}};
	int			i;

	i = -1;
	while (++i < 11 && ft_strcmp(str, move[i]))
		;
	return (i);
}

int			ft_is_sort_checker(int *a, int a_len)
{
	char	*tmp;
	int		*b;
	int		b_len;
	int		act;
	void	(*apply_move[11])(int **, int **, int *, int *);

	if (!(b = (int*)malloc(sizeof(int) * a_len)))
		return (0);
	b_len = 0;
	ft_initialize_function(apply_move);
	while (get_next_line(0, &tmp) > 0 && *tmp)
	{
		if ((act = ft_choose_move(tmp)) <= 10)
			apply_move[act](&a, &b, &a_len, &b_len);
		else
			return (free_all(&a, &b, &tmp));
		free(tmp);
	}
	return (ft_end_test(&a, &b, a_len, b_len));
}
