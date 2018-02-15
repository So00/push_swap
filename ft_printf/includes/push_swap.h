/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:42:26 by atourner          #+#    #+#             */
/*   Updated: 2018/02/15 15:56:06 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

# define PA 0
# define SA 1
# define RA 2
# define RRA 3
# define RR 4
# define SS 5
# define RRR 6
# define RRB 7
# define RB 8
# define SB 9
# define PB 10

typedef struct		s_push_ar
{
	int		*ar;
	int		len;
}					t_push_ar;

int					ft_get_push_ar(int ac, char **av, int **ar);
int					ft_is_sort_checker(int *a, int a_len);
int					free_all(int **a, int **b, char **tmp);
int					is_list_sort(int *act, int len, int descending);
int					order_in_rev(int *act, int len);
int					ft_get_med(t_push_ar *a, int *next_med);
int					ft_get_min(t_push_ar *a, int len);
int					ft_get_highest(t_push_ar *a);
int					is_still_med(t_push_ar *act, int med, int superior);
int					ft_choose_way(t_push_ar *a, int med);

void				ft_push_a(int **a, int **b, int *a_len, int *b_len);
void				ft_push_b(int **a, int **b, int *a_len, int *b_len);
void				ft_swap_a(int **a, int **b, int *a_len, int *b_len);
void				ft_swap_b(int **a, int **b, int *a_len, int *b_len);
void				ft_swap_both(int **a, int **b, int *a_len, int *b_len);
void				ft_rotate_a(int **a, int **b, int *a_len, int *b_len);
void				ft_rotate_b(int **a, int **b, int *a_len, int *b_len);
void				ft_rotate_both(int **a, int **b, int *a_len, int *b_len);
void				ft_rrotate_a(int **a, int **b, int *a_len, int *b_len);
void				ft_rrotate_b(int **a, int **b, int *a_len, int *b_len);
void				ft_rrotate_both(int **a, int **b, int *a_len, int *b_len);
void				ft_initialize_function(void (*apply_move[11])
		(int **a, int **b, int *a_len, int *b_len));
void				ft_len(t_push_ar *a, t_push_ar *b, int *all_med);
void				ft_sort_easy(t_push_ar *a, t_push_ar *b);
void				ft_sort_hard(t_push_ar *a, t_push_ar *b);
void				do_move(int print, t_push_ar *a, t_push_ar *b);
void				ft_sort_bubble(t_push_ar *a, t_push_ar *b);
void				ft_sort_three(t_push_ar *a, t_push_ar *b, int *all_med);
void				ft_push_in_b(t_push_ar *a, t_push_ar *b, int med);

#endif
