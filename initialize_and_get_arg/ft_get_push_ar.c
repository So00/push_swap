/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_push_ar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:22:22 by atourner          #+#    #+#             */
/*   Updated: 2018/03/06 13:27:48 by atourner         ###   ########.fr       */
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
	if (len > 10)
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

static int	check_nb(char **str)
{
	char	*tmp;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i][0] != '-' && str[i][0] != '+' && !ft_isdigit(str[i][0]))
			return (0);
		if (((str[i][0] == '-' || str[i][0] == '+')
		&& (tmp = ft_skip_char(&str[i][1], '0')))
		|| ((tmp = ft_skip_char(str[i], '0'))))
			if (!(ft_isdigit(*tmp) && check_max_and_min_int(str[i], tmp))
					|| !*tmp)
				return (0);
	}
	return (i);
}

static int	check_double(int *a, int len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
			if (a[i] == a[j])
			{
				free(a);
				return (0);
			}
	}
	return (1);
}

static int	*valid_av(int ac, char **av, int *len_a)
{
	int		i;
	int		*a;
	int		j;
	char	**tmp_a;

	i = 0;
	a = NULL;
	if (ac == 2)
		tmp_a = ft_strsplit_space(av[1]);
	else
		tmp_a = &av[1];
	if ((i = check_nb(tmp_a)))
	{
		if ((a = malloc(sizeof(int) * i)))
		{
			*len_a = i;
			i = -1;
			j = -1;
			while (tmp_a[++i])
				a[++j] = ft_atoi(tmp_a[i]);
		}
	}
	if (ac == 2)
		ft_free_ar((void**)tmp_a);
	return (a);
}

int			ft_get_push_ar(int ac, char **av, int **a)
{
	int		a_len;

	a_len = 0;
	if (!(*a = valid_av(ac, av, &a_len)) || !check_double(*a, a_len))
		return (0);
	return (a_len);
}
