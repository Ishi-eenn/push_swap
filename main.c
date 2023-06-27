/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:00:31 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/27 11:27:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_push_swap(t_arg *arg)
{
	if (arg->a->size == 2)
		ft_sort_two(arg, 'a');
	else if (arg->a->size == 3)
		ft_sort_three(arg);
	else if (arg->a->size == 4)
		ft_sort_four(arg);
	else if (arg->a->size == 5)
		ft_sort_five(arg);
	else
		ft_sort(arg);
}

int	main(int argc, char **argv)
{
	t_arg	*arg;

	if (argc <= 1)
		return (0);
	arg = malloc(sizeof(t_arg));
	if (arg == NULL)
		return (0);
	arg->a = ft_stacknew();
	arg->b = ft_stacknew();
	ft_get_stack_args(arg, argc, argv);
	ft_check_overlap(arg);
	ft_check_sorted(arg);
	ft_push_swap(arg);
	ft_free(arg);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q push_swap");
// }
