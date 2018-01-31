/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:36:43 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 13:38:57 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int		*a;
	int		a_len;

	if (ac == 1 || !(a_len = ft_get_push_ar(ac, av, &a)))
		ft_printf("Error\n");
	else if (ft_is_sort_checker(a, a_len))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
