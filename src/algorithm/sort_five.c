/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciamar <luciamar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:35:05 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/04 23:01:49 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *backpack)
{
	int	min_val;
	int	pos;
	int	i;

	min_val = backpack->stack_a[0];
	pos = 0;
	i = 1;
	while (i < backpack->len_a)
	{
		if (backpack->stack_a[i] < min_val)
		{
			min_val = backpack->stack_a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

static void	move_min_to_top(t_stack *backpack, t_stats *totebag, int pos)
{
	int	min_val;

	min_val = backpack->stack_a[pos];
	if (pos <= backpack->len_a / 2)
	{
		while (backpack->stack_a[0] != min_val)
			ra(backpack, totebag);
	}
	else
	{
		while (backpack->stack_a[0] != min_val)
			rra(backpack, totebag);
	}
}

void	sort_five(t_stack *backpack, t_stats *totebag)
{
	int	pos;

	if (!totebag->disorder)
		return ;
	while (backpack->len_a > 3)
	{
		pos = find_min_pos(backpack);
		move_min_to_top(backpack, totebag, pos);
		pb(backpack, totebag);
	}
	sort_three(backpack, totebag);
	while (backpack->len_b > 0)
		pa(backpack, totebag);
}
