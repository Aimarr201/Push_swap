/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:11:03 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/02 20:03:14 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_disorder(float disorder)
{
	int		integer_part;
	int		decimal_part;
	char	tmp;

	write(2, "[bench] disorder: ", 18);
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

void	ft_print_strat(t_stats *totebag)
{
	write(2, "[bench] strategy: ", 19);
	if (totebag->algorithm_flag == 1)
		write(2, "Simple", 7);
	else if (totebag->algorithm_flag == 2)
		write(2, "Medium", 6);
	else if (totebag->algorithm_flag == 3)
		write(2, "Complex", 7);
	else
	{
		if (totebag->disorder > 0.2)
			write(2, " / O(n²)\n", 9);
		else if (totebag->disorder > 0.5)
			write(2, " / O(n√n)\n", 10);
		else
			write(2, " / O(nlogn)\n", 12);
	}
}

void	ft_print_bench(t_stats *totebag)
{
	ft_print_disorder(totebag->disorder);
	ft_print_strat(totebag);
	print("[bench] totalops: %d", totebag->total_ops);
	print("[bench] pa: %d	pb %d", totebag->pa, totebag->pb);
	print("[bench] sa: %d sb %d ss %d",
		totebag->sa, totebag->sb, totebag->ss);
	print("[bench] ra: %d	rb %d	rr %d",
		totebag->ra, totebag->rb, totebag->rr);
	print("[bench] rra: %d	rrb %d	rrr %d",
		totebag->rra, totebag->rrb, totebag->rrr);
}

void	print(char const *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i] == 'd')
		{
			i++;
			ft_printnbr(str[i]);
		}
		else
			write(2, '&str[i]', 1);
		i++;
	}
	va_end(list);
	return (count);
}

void	ft_printnbr(int n)
{
	if (n > 9)
		ft_printnumber(n / 10);
	write(2, (n % 10) + '0', 1);
}
