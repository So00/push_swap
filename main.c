/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:40 by atourner          #+#    #+#             */
/*   Updated: 2018/01/20 22:42:41 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main()
{
	int *tab;
	int	*tab2;
	int	a_len = 5;
	int	b_len = 5;

	tab = malloc(sizeof(int) * 15);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	tab[4] = 4;
	tab2 = malloc(sizeof(int) * 15);
	tab2[0] = 5;
	tab2[1] = 6;
	tab2[2] = 7;
	tab2[3] = 8;
	tab2[4] = 9;

	//ft_push_a(&tab, &tab2, &a_len, &b_len);
	ft_push_b(&tab, &tab2, &a_len, &b_len);
	//ft_swap_a(&tab, 5);
	//ft_swap_both(&tab, &tab2, &a_len, &b_len);
	//ft_rrotate_both(&tab, &tab2, &a_len, &b_len);
	//ft_rotate_both(&tab, &tab2, &a_len, &b_len);
	for (int i = 0; i < b_len || i < a_len; i++)
	{
		if (a_len < b_len && b_len - i - a_len <= 0)
			printf("	%d", tab[a_len - b_len + i]);
		else if (a_len >= b_len)
			printf("	%d", tab[i]);
		else
			printf("	");
		if (b_len < a_len && a_len - i - b_len <= 0)
			printf("	%d", tab2[b_len - a_len + i]);
		else if (b_len >= a_len)
			printf("	%d", tab2[i]);
		printf("\n");
	}
	printf("----------------------------------\n	a	b\n");
}
