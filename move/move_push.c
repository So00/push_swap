/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:41:41 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 01:18:28 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_push_a(int **a, int **b, int *a_len, int *b_len)
{
	int		i;

	if (*b_len)
	{
		i = (*a_len) + 1;
		while (--i)
			a[0][i] = a[0][i - 1];
		a[0][0] = b[0][0];
		*a_len += 1;
		i = -1;
		while (++i < *b_len)
			b[0][i] = b[0][i + 1];
		*b_len -= 1;
	}
}

void	ft_push_b(int **a, int **b, int *a_len ,int *b_len)
{
	int		i;

	if (*a_len)
	{
		i = (*b_len) + 1;
		while (--i)
			b[0][i] = b[0][i - 1];
		b[0][0] = a[0][0];
		*b_len += 1;
		i = -1;
		while (++i < *a_len)
			a[0][i] = a[0][i + 1];
		*a_len -= 1;
	}
}
