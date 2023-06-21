/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:01:50 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/21 16:40:07 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate_a(t_arg *arg)
{
	t_node	*node;

	if (arg->a->size < 2)
		return (0);
	node = ft_pop(arg->a);
	ft_pushback(arg->a, node);
	return (1);
}

static int	ft_rotate_b(t_arg *arg)
{
	t_node	*node;

	if (arg->b->size < 2)
		return (0);
	node = ft_pop(arg->b);
	ft_pushback(arg->b, node);
	return (1);
}
