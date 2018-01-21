/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_list_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:01:14 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 01:03:15 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern const char g_move[11][4];

static int	free_all(int **a, int **b, char **tmp)
{
	free(*a);
	free(*b);
	if (tmp)
		free(*tmp);
	return (0);
}

int			ft_end_test(int **a, int **b, int a_len, int b_len)
{
	int		ret;

	if (b_len)
		return (free_all(a, b, NULL));
	ret = -1;
	while (++ret < a_len - 1)
		if ((*a)[ret] > (*a)[ret + 1])
			return (free_all(a, b, NULL));
	free(*a);
	free(*b);
	return (1);
}

int			ft_is_list_sort(int	*a, int a_len)
{
	char	*tmp;
	int		*b;
	int		b_len;
	int		act;
	void	(*apply_move[11])(int **a, int **b, int *a_len, int *b_len);

	if (!(b = (int*)malloc(sizeof(int) * a_len)))
		return (0);
	b_len = 0;
	ft_initialize_function(apply_move);
	while (get_next_line(0, &tmp) > 0 && *tmp)
	{
		act = -1;
		while (++act < 11 && ft_strcmp(g_move[act], tmp) != 0)
			;
		if (act <= 10)
			apply_move[act](&a, &b, &a_len, &b_len);
		else
			return (free_all(&a, &b, &tmp));
		free(tmp);
	}
	free(tmp);
	return (ft_end_test(&a, &b, a_len, b_len));
}
