/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:14:31 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/22 11:39:25 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_exit(int judge, t_arg *arg)
{
	if (judge == 1)
		write(1, "Error\n", 6);
	// ft_free(arg); //全部消す処理必要
	exit(1);
}