/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:09:43 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/24 20:13:58 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_error(int code, t_arg *arg)
{
	if (code == 1)
		write(1, "Error\n", 6);
	ft_free(arg);
	exit(1);
}

static void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*to_free;


	node = stack->top;

	while (node != NULL)
	{
		to_free = node;
		node = node->prev;
		free(to_free);
	}
}

void	ft_free(t_arg *arg)
{
	if (arg == NULL)
		return ;
	if (arg->a != NULL)
	{
		if (arg->a->size != 0)
			free_stack(arg->a);
		free(arg->a);
	}
	if (arg->b != NULL)
	{
		if (arg->b->size != 0)
			free_stack(arg->b);
		free(arg->b);
	}
	free(arg);
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
