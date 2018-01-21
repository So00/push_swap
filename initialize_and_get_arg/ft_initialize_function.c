/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:41:12 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 04:18:19 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			free_all(int **a, int **b, char **tmp)
{
	if (a)
		free(*a);
	if (b)
		free(*b);
	if (tmp)
		free(*tmp);
	return (0);
}

void		ft_initialize_function(void (*apply_move[11])())
{
	apply_move[0] = &ft_push_a;
	apply_move[1] = &ft_swap_a;
	apply_move[2] = &ft_rotate_a;
	apply_move[3] = &ft_rrotate_a;
	apply_move[4] = &ft_rotate_both;
	apply_move[5] = &ft_swap_both;
	apply_move[6] = &ft_rrotate_both;
	apply_move[7] = &ft_rrotate_b;
	apply_move[8] = &ft_rotate_b;
	apply_move[9] = &ft_swap_b;
	apply_move[10] = &ft_push_b;
}
