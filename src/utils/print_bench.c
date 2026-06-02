/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:11:03 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/01 19:42:36 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_disorder(float disorder)
{
	int		integer_part;
	int		decimal_part;
	char	tmp;

	integer_part = (int)disorder;
	decimal_part = (int)((disorder - integer_part) * 100);
	if (integer_part >= 100)
	{
		tmp = '0' + (integer_part / 100);
		write(2, &tmp, 1);
	}
	if (integer_part >= 10)
	{
		tmp = '0' + ((integer_part % 100) / 10);
		write(2, &tmp, 1);
	}
	tmp = '0' + (integer_part % 10);
	write(2, &tmp, 1);
	write(2, ".", 1);
	tmp = '0' + (decimal_part / 10);
	write(2, &tmp, 1);
	tmp = '0' + (decimal_part % 10);
	write(2, &tmp, 1);
	write(2, "%\n", 2);
}

void ft_print_bench(t_stats *totebag)
{
	write(2, "[bench] disorder: ", 18);
	ft_print_disorder(totebag->disorder);
}
