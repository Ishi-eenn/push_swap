/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:20:47 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/01 00:49:27 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_atoc(const char *str, t_arg *arg, int *index)
{
	int			sign;
	int			len;
	long long	result;

	sign = 1;
	len = 0;
	if (str[*index] == '-' || str[*index] == '+')
		if (str[(*index)++] == '-')
			sign *= -1;
	result = 0;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10 + (str[(*index)++] - '0');
		len++;
	}
	result = result * (sign);
	if (len > 10 || result < INT_MIN || result > INT_MAX || len == 0)
		ft_print_error(arg);
	return ((int)result);
}

static void	ft_judge_pb(const char *str, t_arg *arg, int *index, int *cnt)
{
	t_node	*buff;

	buff = ft_lstnew(ft_atoc(str, arg, index));
	if (buff == NULL)
		ft_print_error(arg);
	ft_pushback(arg->a, buff);
	(*cnt)++;
}

static void	ft_judge_error(int *index, int *flag, int *cnt, t_arg *arg)
{
	if (*index == 1 && *cnt > 1)
		*flag = 1;
	if ((*index >= 2 && *cnt > 1) || (*index >= 2 && *flag == 1))
		ft_print_error(arg);
}

void	ft_get_stack_args(t_arg *arg, int ac, char **av)
{
	int	i;
	int	j;
	int	cnt;
	int	flag;

	i = 0;
	flag = 0;
	while (++i < ac)
	{
		j = 0;
		cnt = 0;
		while (av[i][j] != '\0')
		{
			while (av[i][j] != '\0' && ft_isspace(av[i][j]) != 0)
				j++;
			if (av[i][j] == '\0')
				break ;
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				ft_print_error(arg);
			ft_judge_pb(av[i], arg, &j, &cnt);
			ft_judge_error(&i, &flag, &cnt, arg);
		}
		if (j == 0)
			ft_print_error(arg);
	}
}
