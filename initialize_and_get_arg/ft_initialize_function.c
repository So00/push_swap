/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:41:12 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 00:08:25 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	g_move[11][4] = {{"pa\0"},{"sa\0"},{"ra\0"},{"rra\0"},
	{"rr\0"},{"ss\0"},{"rrr\0"},{"rrb\0"},{"rb\0"},{"sb\0"},{"pb\0"}};

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
