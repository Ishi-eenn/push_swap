/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:04:51 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/22 11:39:11 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoc(const char *str, t_arg *arg, int *j)
{
	int			sign;
	int			len;
	long long	result;

	sign = 1;
	len = 0;
	if (str[*j] == '-' || str[*j] == '+')
		if(str[(*j)++] == '-')
			sign *= -1;
	result = 0;
	while (ft_isdigit(str[*j]))
	{
		result = result * 10 + (str[(*j)++] - '0');
		len++;
	}
	result = result * (sign);
	if (len > 10 || result < INT_MIN || result > INT_MAX || len == 0)
		print_error(1, arg);
	return ((int)result);
}

void	ft_get_stack(t_arg *arg, int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] != '\0' && ft_isspace(argv[i][j]) != 0)
				j++;
			if (argv[i][j] == '\0')
				break ;
			if (ft_isdigit(argv[i][j]) == 0
				&& argv[i][j] != '-' && argv[i][j] != '+')
				print_error(1, arg);
			ft_pushback(arg->a, ft_lstnew(ft_atoc(argv[i], arg, &j)));
			flag = 1;
		}
		if (flag == 0)
			print_error(1, arg);
	}
}
