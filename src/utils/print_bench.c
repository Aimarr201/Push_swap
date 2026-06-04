/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:11:03 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/04 12:59:46 by amendibi         ###   ########.fr       */
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
	ft_print("[bench] strategy: ");
	if (totebag->algorithm_flag == 1)
	{
		ft_print("Simple / O(n²)\n");
		return ;
	}
	else if (totebag->algorithm_flag == 2)
	{
		ft_print("Medium / O(n√n)\n");
		return ;
	}
	else if (totebag->algorithm_flag == 3)
	{
		ft_print("Complex / O(nlogn)\n");
		return ;
	}
	else if (totebag->algorithm_flag == 0 || totebag->algorithm_flag == 4)
		ft_print("Adaptive");
	if (totebag->disorder < 0.2)
		ft_print(" / O(n²)\n");
	else if (totebag->disorder < 0.5)
		ft_print(" / O(n√n)\n");
	else
		ft_print(" / O(nlogn)\n");

}

void	ft_print_bench(t_stats *totebag)
{
	if (totebag->bench_flag)
	{
		ft_print_disorder(totebag->disorder);
		ft_print_strat(totebag);
		ft_print("[bench] totalops: %d\n", totebag->total_ops);
		ft_print("[bench] pa: %d pb %d\n", totebag->pa, totebag->pb);
		ft_print("[bench] sa: %d sb %d ss %d\n",
			totebag->sa, totebag->sb, totebag->ss);
		ft_print("[bench] ra: %d rb %d rr %d\n",
			totebag->ra, totebag->rb, totebag->rr);
		ft_print("[bench] rra: %d rrb %d rrr %d\n",
			totebag->rra, totebag->rrb, totebag->rrr);
	}
}

void	ft_print(char const *str, ...)
{
	va_list	list;
	int		i;
	int		is_last;

	is_last = 0;
	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			if (str[i + 2] == '\n')
				is_last++;
			i++;
			ft_printnbr(va_arg(list, int), is_last);
		}
		else
			write(2, &str[i], 1);
		i++;
	}
	va_end(list);
}

void	ft_printnbr(int nbr, int is_last)
{
	int		divisor;
	int		width;
	char	c;

	divisor = 1;
	while (divisor <= nbr / 10)
		divisor *= 10;
	width = 0;
	while (divisor >= 1)
	{
		c = ((nbr / divisor) % 10) + '0';
		write(2, &c, 1);
		divisor /= 10;
		width++;
	}
	if (!is_last)
	{
		while (width < 6)
		{
			write(2, " ", 1);
			width++;
		}
	}
}
