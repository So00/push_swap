/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:16 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 01:10:00 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap_a(int **a, int **b, int *a_len, int *b_len)
{
	int		tmp;

	if (*a_len > 1)
	{
		tmp = a[0][1];
		a[0][1] = a[0][0];
		a[0][0] = tmp;
	}
}

void		ft_swap_b(int **a, int **b, int *a_len, int *b_len)
{
	int		tmp;

	if (*b_len > 1)
	{
		tmp = b[0][1];
		b[0][1] = b[0][0];
		b[0][0] = tmp;
	}
}

void		ft_swap_both(int **a, int **b, int *a_len, int *b_len)
{
	if (*a_len)
		ft_swap_a(a, b, a_len, b_len);
	if (*b_len)
		ft_swap_b(b, b, a_len, b_len);
}
