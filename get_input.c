/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:20:47 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/02 21:32:14 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_judge_pb(const char *str, t_arg *arg, int *index)
{
	t_node	*buff;

	buff = ft_lstnew(ft_atoc(str, arg, index));
	if (buff == NULL)
		ft_print_error(arg);
	ft_pushback(arg->a, buff);
}

void	ft_get_stack_args(t_arg *arg, int ac, char **av)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		flag = 0;
		while (av[i][j] != '\0')
		{
			while (av[i][j] != '\0' && ft_isspace(av[i][j]) != 0)
				j++;
			if (av[i][j] == '\0' && flag == 1)
				break ;
			if (av[i][j] == '\0' && flag == 0)
				ft_print_error(arg);
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				ft_print_error(arg);
			ft_judge_pb(av[i], arg, &j);
			flag = 1;
		}
		if (j == 0)
			ft_print_error(arg);
	}
}

void	ft_check_sorted(t_arg *arg)
{
	t_node	*node;

	node = arg->a->top;
	while (node->prev)
	{
		if (node->data > node->prev->data)
			return ;
		node = node->prev;
	}
	exit(0);
}

void	ft_check_overlap(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	node1 = arg->a->top;
	while (node1 != NULL)
	{
		node2 = node1->prev;
		while (node2 != NULL)
		{
			if (node1->data == node2->data)
				ft_print_error(arg);
			node2 = node2->prev;
		}
		node1 = node1->prev;
	}
}
