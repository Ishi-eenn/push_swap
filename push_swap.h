/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:27:58 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/20 21:45:39 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_arg
{
	int				pivot[2];
	struct s_stack	*a;
	struct s_stack	*b;
}	t_arg;

t_node	*ft_lstnew(int content);
t_node	*ft_pop(t_stack *stack);
t_stack	*ft_stacknew(void);
void	ft_push(t_stack *stack, t_node *node);
void	ft_pushback(t_stack *stack, t_node *node);

#endif
