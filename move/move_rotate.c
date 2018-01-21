/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:11 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 01:08:46 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rotate_a(int **a, int **b, int *a_len, int *b_len)
{
	int		tmp;
	int		i;

	if (*a_len)
	{
		i = -1;
		tmp = a[0][0];
		while (++i < *a_len)
			a[0][i] = a[0][i + 1];
		a[0][*a_len - 1] = tmp;
	}
}

void	ft_rotate_b(int **a, int **b, int *a_len, int *b_len)
{
	int		tmp;
	int		i;

	if (*b_len)
	{
		i = -1;
		tmp = b[0][0];
		while (++i < *b_len)
			b[0][i] = b[0][i + 1];
		b[0][*b_len - 1] = tmp;
	}
}

void	ft_rotate_both(int **a, int **b, int *a_len, int *b_len)
{
	if (*a_len)
		ft_rotate_a(a, b, a_len, b_len);
	if (*b_len)
		ft_rotate_b(a, b, a_len, b_len);
}
