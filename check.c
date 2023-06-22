/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:56:53 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/22 11:39:38 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_overlap(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	node1 = arg->a->top;
	while (node1 != NULL)
	{
		node2 = node1->prev;
		while (node2 != NULL)
		{
			if (node1->content == node2->content)
				print_error(1, arg);
			node2 = node2->prev;
		}
		node1 = node1->prev;
	}
}

void	check_sorted(t_arg *arg)
{
	t_node	*node;

	node = arg->a->top;
	while (node->prev != NULL)
	{
		if (node->content > node->prev->content)
			return ;
		node = node->prev;
	}
	ft_free(arg);
	exit(0);
}
