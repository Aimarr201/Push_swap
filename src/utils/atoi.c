/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:06:35 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/03 15:39:44 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_if_is_in_range(long num, char *str, int negative)
{
	if (negative)
	{
		if (num > INT_MAX / 10)
			ft_error();
		if (num == INT_MAX / 10 && (*str - 48) > 8)
			ft_error();
	}
	else
	{
		if (num > INT_MAX / 10)
			ft_error();
		if (num == INT_MAX / 10 && (*str - 48) > 7)
			ft_error();
	}
}

int	ft_atoi(const char *str)
{
	long	num;
	int		negative;

	num = 0;
	negative = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	if (*str < '0' || *str > '9')
		ft_error();
	while (*str >= '0' && *str <= '9')
	{
		check_if_is_in_range(num, str, negative);
		num = num * 10 + *str - 48;
		str++;
	}
	if (negative == 1)
		return (num * -1);
	return ((int)num);
}
