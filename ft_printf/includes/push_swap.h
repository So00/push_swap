/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:26 by atourner          #+#    #+#             */
/*   Updated: 2018/02/02 19:22:37 by atourner         ###   ########.fr       */
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

typedef struct		s_push_ar
{
	int		*ar;
	int		len;
}					t_push_ar;

int		ft_get_push_ar(int ac, char **av, int **ar);
int		ft_is_sort_checker(int *a, int a_len);
int		free_all(int **a, int **b, char **tmp);
int		is_list_sort(int *act, int len, int descending);
int		order_in_rev(int *act, int len);
int		ft_get_med(t_push_ar *a);
int		ft_get_min(t_push_ar *a, int len);
int		ft_get_highest(t_push_ar *a);
int		is_still_med(t_push_ar *act, int med, int superior);

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
void	ft_sort_easy(t_push_ar *a, t_push_ar *b, void (*move[11])());
void	ft_sort_hard(t_push_ar *a, t_push_ar *b, void (*move[11])());
void	do_move(int print, t_push_ar *a, t_push_ar *b, void (*move[11])());
void	ft_sort_bubble(t_push_ar *a, t_push_ar *b, void (*move[11])());
void	ft_sort_three(t_push_ar *a, t_push_ar *b, void (*move[11])(),
		int next_med);

#endif
