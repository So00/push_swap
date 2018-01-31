/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <mavin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:19:16 by atourner          #+#    #+#             */
/*   Updated: 2018/01/31 13:39:30 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_max_and_min_int(char *str, char *stat)
{
	int			len;
	static char	max[11] = "2147483647\0";
	static char	min[11] = "2147483648\0";

	len = -1;
	while (stat[++len])
		if (!ft_isdigit(stat[len]))
			return (0);
	if (len == 10)
	{
		if (*str == '-' && ft_strcmp(stat, min) > 0)
			return (0);
		else if (*str != '-' && ft_strcmp(stat, max) > 0)
			return (0);
	}
	return (1);
}

static int	check_nb(char *str)
{
	char	*tmp;

	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		return (0);
	if (((*str == '-'|| *str == '+') && (tmp = ft_skip_char(&str[1], '0')))
			|| (ft_isdigit(*str) && (tmp = ft_skip_char(str, '0'))))
	{
		if ((ft_isdigit(*tmp) && check_max_and_min_int(str, tmp)) || !*tmp)
			return (1);
	}
	return (0);
}

static int	*valid_av(int ac, char **av, int *len_a)
{
	int		i;
	int		*a;
	int		j;
	char	**tmp_a;

	i = (ac == 2 ? -1 : 0);
	a = NULL;
	if (ac == 2)
		tmp_a = ft_strsplit_space(av[1]);
	else
		tmp_a = av;
	while (tmp_a[++i])
		if (!check_nb(tmp_a[i]))
			return (NULL);
	if (!(a = malloc(sizeof(int) * i)))
		return (NULL);
	*len_a = (ac == 2 ? i : i - 1);
	i = (ac == 2 ? -1 : 0);
	j = -1;
	while (tmp_a[++i])
		a[++j] = ft_atoi(tmp_a[i]);
	if (ac == 2)
		ft_free_ar((void**)tmp_a);
	return (a);
}

int			ft_get_push_ar(int ac, char **av, int **a)
{
	int		a_len;

	a_len = 0;
	if (!(*a = valid_av(ac, av, &a_len)))
		return (0);
	return (a_len);
}
