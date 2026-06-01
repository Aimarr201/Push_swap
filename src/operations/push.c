/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:43:19 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/01 19:06:35 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *backpack, t_stats *totebag)
{
	int	i;

	if (backpack->len_a < 1)
		return ;
	i = backpack->len_b;
	while (i > 0)
	{
		backpack->stack_b[i] = backpack->stack_b[i - 1];
		i--;
	}
	backpack->stack_b[0] = backpack->stack_a[0];
	backpack->len_b++;
	i = 0;
	while (i < backpack->len_a - 1)
	{
		backpack->stack_a[i] = backpack->stack_a[i + 1];
		i++;
	}
	backpack->len_a--;
	totebag->pb++;
	totebag->total_ops++;
	ft_putstr("pb\n");
}

void	pa(t_stack *backpack, t_stats *totebag)
{
	int	i;

	if(backpack->len_b < 1)
		return ;
	i = backpack->len_a;
	while (i > 0)
	{
		backpack->stack_a[i] = backpack->stack_a[i - 1];
		i--;
	}
	backpack->stack_a[0] = backpack->stack_b[0];
	backpack->len_a++;
	i = 0;
	while (i < backpack->len_b - 1)
	{
		backpack->stack_b[i] = backpack->stack_b[i + 1];
		i++;
	}
	backpack->len_b--;
	totebag->pa++;
	totebag->total_ops++;
	ft_putstr("pa\n");
}
