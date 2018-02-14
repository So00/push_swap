/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:41:21 by atourner          #+#    #+#             */
/*   Updated: 2018/02/12 14:50:45 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rrotate_a(int **a, int **b, int *a_len, int *b_len)
{
	int		i;
	int		tmp;

	if (*a_len)
	{
		i = *a_len;
		tmp = a[0][*a_len - 1];
		while (--i)
		{
			a[0][i] = a[0][i - 1];
		}
		a[0][0] = tmp;
	}
}

void	ft_rrotate_b(int **a, int **b, int *a_len, int *b_len)
{
	int		i;
	int		tmp;

	if (*b_len)
	{
		i = *b_len;
		tmp = b[0][*b_len - 1];
		while (--i)
		{
			b[0][i] = b[0][i - 1];
		}
		b[0][0] = tmp;
	}
}

void	ft_rrotate_both(int **a, int **b, int *a_len, int *b_len)
{
	if (*a_len)
		ft_rrotate_a(a, b, a_len, b_len);
	if (*b_len)
		ft_rrotate_b(a, b, a_len, b_len);
}
