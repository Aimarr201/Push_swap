/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_adaptative.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:47:15 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/04 21:25:07 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *backpack, t_stats *totebag)
{
	if (backpack->stack_a[0] > backpack->stack_a[1])
		sa(backpack, totebag);
}

void	sort_three(t_stack *backpack, t_stats *totebag)
{
	int	top;
	int	mid;
	int	bot;

	top = backpack->stack_a[0];
	mid = backpack->stack_a[1];
	bot = backpack->stack_a[2];
	if (top > mid && top > bot && mid < bot)
		ra(backpack, totebag);
	else if (top > mid && top > bot && mid > bot)
	{
		sa(backpack, totebag);
		rra(backpack, totebag);
	}
	else if (top > mid && top < bot)
		sa(backpack, totebag);
	else if (top < mid && top < bot && mid > bot)
	{
		rra(backpack, totebag);
		sa(backpack, totebag);
	}
	else if (top < mid && top > bot)
		rra(backpack, totebag);
}

int	find_min_pos(t_stack *backpack)
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

void	move_min_to_top(t_stack *backpack, t_stats *totebag, int pos)
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

void	dispatch_adaptative(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_a == 2)
		sort_two(backpack, totebag);
	else if (backpack->len_a == 3)
		sort_three(backpack, totebag);
	else if (backpack->len_a <= 5)
		sort_five(backpack, totebag);
	else
	{
		if (totebag->disorder < 0.2)
			algorithm_simple(backpack, totebag);
		else if (totebag->disorder < 0.5)
			algorithm_medium(backpack, totebag);
		else
			algorithm_complex(backpack, totebag);
	}
}
