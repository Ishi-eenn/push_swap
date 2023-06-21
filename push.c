/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:01:43 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/21 16:41:58 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push_a(t_arg *arg)
{
	t_node	*new;
	if (arg->b->size == 0)
		return (0);
	new = ft_pop(arg->b);
	ft_push(arg->a, new);
	return (1);
}

static int	ft_push_b(t_arg *arg)
{
	t_node	*new;
	if (arg->a->size == 0)
		return (0);
	new = ft_pop(arg->b);
	ft_push(arg->a, new);
	return (1);
}

int	ft_judge_push(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		result = pa(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("pa\n", 1);
	}
	if (type == 'b')
	{
		result = pb(arg);
		if (result != 0 && print != 0)
			ft_putstr_fd("pb\n", 1);
	}
	return (1);
}
