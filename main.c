/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:27:53 by tsishika          #+#    #+#             */
/*   Updated: 2023/06/22 11:39:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	ft_push_swap();
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
