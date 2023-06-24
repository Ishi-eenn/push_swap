/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:52:15 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/24 22:36:46 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*ft_lstnew(int data)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	if (!ret)
		return (0);
	ret->data = data;
	ret->prev = 0;
	ret->next = 0;
	return (ret);
}

t_stack	*ft_stacknew(void)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		return (0);
	ret->top = 0;
	ret->bottom = 0;
	ret->size = 0;
	return (ret);
}

void	ft_pushback(t_stack *stack, t_node *node)
{
	if (node == NULL)
		return ;
	if (stack->size != 0)
	{
		node->prev = NULL;
		node->next = stack->bottom;
		stack->bottom->prev = node;
		stack->bottom = node;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

void	ft_push(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	if (stack->size == 0)
	{
		node->prev = 0;
		node->next = 0;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->next = node;
		node->next = 0;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->size++;
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*ret;

	if (stack->size == 0)
		return (0);
	if (stack->size == 1)
	{
		ret = stack->top;
		stack->top = 0;
		stack->bottom = 0;
	}
	else
	{
		ret = stack->top;
		stack->top->prev->next = 0;
		stack->top = stack->top->prev;
	}
	stack->size--;
	return (ret);
}
