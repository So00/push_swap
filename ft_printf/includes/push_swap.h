/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:26 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 05:34:41 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

#define pa 0
#define sa 1
#define ra 2
#define rra 3
#define rr 4
#define ss 5
#define rrr 6
#define rrb 7
#define rb 8
#define sb 9
#define pb 10

int		ft_get_push_ar(int ac, char **av, int **ar);
int		ft_is_sort_checker(int *a, int a_len);
int		free_all(int **a, int **b, char **tmp);
int		ft_sort_easy(int *a, int *b, int *a_len, int *b_len);

void	ft_push_a(int **a, int **b, int *a_len, int *b_len);
void	ft_push_b(int **a, int **b, int *a_len, int *b_len);
void	ft_swap_a(int **a, int **b, int *a_len, int *b_len);
void	ft_swap_b(int **a, int **b, int *a_len, int *b_len);
void	ft_swap_both(int **a, int **b, int *a_len, int *b_len);
void	ft_rotate_a(int **a, int **b, int *a_len, int *b_len);
void	ft_rotate_b(int **a, int **b, int *a_len, int *b_len);
void	ft_rotate_both(int **a, int **b, int *a_len, int *b_len);
void	ft_rrotate_a(int **a, int **b, int *a_len, int *b_len);
void	ft_rrotate_b(int **a, int **b, int *a_len, int *b_len);
void	ft_rrotate_both(int **a, int **b, int *a_len, int *b_len);
void	ft_initialize_function(void (*apply_move[11])
		(int **a, int **b, int *a_len, int *b_len));

#endif
