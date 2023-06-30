/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:09:43 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/01 00:15:08 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(t_arg *arg)
{
	write(1, "Error\n", 6);
	ft_free(arg);
	exit(1);
}

int	ft_abs(int data)
{
	if (data < 0)
		return (data * (-1));
	return (data);
}

void	ft_get_pivot(t_arg *arg)
{
	t_node	*node;
	t_node	*comp;
	int		count;

	node = arg->a->top;
	while (node)
	{
		comp = arg->a->top;
		count = 0;
		while (comp)
		{
			if (node->data > comp->data)
				count++;
			comp = comp->prev;
		}
		if (count == arg->a->size / 3)
			arg->pivot[0] = node->data;
		if (count == (arg->a->size * 2) / 3)
			arg->pivot[1] = node->data;
		node = node->prev;
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
