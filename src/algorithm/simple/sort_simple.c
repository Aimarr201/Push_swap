/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:00:00 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/04 20:11:12 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_to_b(t_stack *backpack, t_stats *totebag)
{
	int	position_of_smallest;
	int	i;
	int	smallest;

	while (backpack->len_a)
	{
		i = 0;
		position_of_smallest = 0;
		smallest = backpack->stack_a[0];
		while (i < backpack->len_a)
		{
			if (backpack->stack_a[i] < smallest)
			{
				position_of_smallest = i;
				smallest = backpack->stack_a[i];
			}
			i++;
		}
		while (position_of_smallest > 0)
		{
			ra(backpack, totebag);
			position_of_smallest--;
		}
		pb(backpack, totebag);
	}
}

void	comeback_to_a(t_stack *backpack, t_stats *totebag)
{
	while (backpack->len_b)
		pa(backpack, totebag);
}

void	algorithm_simple(t_stack *backpack, t_stats *totebag)
{
	if (!totebag->disorder)
		return ;
	if (backpack->len_a <= 1)
		return ;
	smallest_to_b(backpack, totebag);
	comeback_to_a(backpack, totebag);
	while (backpack->len_b > 0)
		pa(backpack, totebag);
}
