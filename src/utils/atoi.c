/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:06:35 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/04 13:06:16 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_range(long num, const char *str, int negative, t_stack *backpack)
{
	if (negative)
	{
		if (num > INT_MAX / 10)
			ft_error_free_back(backpack);
		if (num == INT_MAX / 10 && (*str - 48) > 8)
			ft_error_free_back(backpack);
	}
	else
	{
		if (num > INT_MAX / 10)
			ft_error_free_back(backpack);
		if (num == INT_MAX / 10 && (*str - 48) > 7)
			ft_error_free_back(backpack);
	}
}

int	ft_atoi(const char *str, t_stack *backpack)
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
		ft_error_free_back(backpack);
	while (*str >= '0' && *str <= '9')
	{
		check_range(num, str, negative, backpack);
		num = num * 10 + *str - 48;
		str++;
	}
	if (negative == 1)
		return (num * -1);
	return ((int)num);
}
