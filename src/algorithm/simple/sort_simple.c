/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:00:00 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/03 16:21:50 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_pos(t_stack *backpack)
{
	int	i;

	i = 0;
	while (i < backpack->len_b)
	{
		if (backpack->stack_a[0] > backpack->stack_b[i])
			return (i);
		i++;
	}
	return (backpack->len_b);
}

void	rotate_b_to_pos(t_stack *backpack, t_stats *totebag, int pos)
{
	int	steps;

	if (pos == 0)
		return ;
	if (pos <= backpack->len_b / 2)
	{
		steps = pos;
		while (steps-- > 0)
			rb(backpack, totebag);
	}
	else
	{
		steps = backpack->len_b - pos;
		while (steps-- > 0)
			rrb(backpack, totebag);
	}
}

void	push_all_to_b(t_stack *backpack, t_stats *totebag)
{
	int	pos;

	while (backpack->len_a > 0)
	{
		pos = find_insert_pos(backpack);
		rotate_b_to_pos(backpack, totebag, pos);
		pb(backpack, totebag);
	}
}

void	algorithm_simple(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_a <= 1)
		return ;
	push_all_to_b(backpack, totebag);
	while (backpack->len_b > 0)
		pa(backpack, totebag);
}
