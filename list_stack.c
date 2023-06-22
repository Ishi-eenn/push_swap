/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:14:30 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/22 10:43:09 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*ft_stacknew(void)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->size = 0;
	node->top = NULL;
	node->bottom = NULL;
	return (node);
}

void	ft_push(t_stack *stack, t_node *node)
{
	if (node == NULL)
		return ;
	if (stack->size == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->next = node;
		node->next = NULL;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->size++;
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (NULL);
	if (stack->size == 1)
	{
		node = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		node = stack->top;
		stack->top->prev->next = NULL;
		stack->top = stack->top->prev;
	}
	stack->size--;
	return (node);
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
