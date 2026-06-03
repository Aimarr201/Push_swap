/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:00:00 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/02 19:46:36 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *backpack, t_stats *totebag, int pos)
{
	int	steps;

	if (pos <= backpack->len_a / 2)
	{
		while (pos-- > 0)
			ra(backpack, totebag);
	}
	else
	{
		steps = backpack->len_a - pos;
		while (steps -- > 0)
			rra(backpack, totebag);
	}
	pb(backpack, totebag);
}

void	empty_b_to_a(t_stack *backpack, t_stats *totebag)
{
	int	max_pos;
	int	steps;

	while (backpack->len_b > 0)
	{
		max_pos = find_max_in_b(backpack);
		if (max_pos <= backpack->len_b / 2)
		{
			while (max_pos -- > 0)
				rb(backpack, totebag);
		}
		else
		{
			steps = backpack->len_b - max_pos;
			while (steps -- > 0)
				rrb(backpack, totebag);
		}
		pa(backpack, totebag);
	}
}

void	process_chunk(t_stack *backpack, t_stats *totebag, t_c *c)
{
	int	chunk;
	int	pos;

	chunk = 0;
	while (chunk < c->max)
	{
		while (1)
		{
			pos = find_closest_chunk_elem(backpack, chunk, c->size);
			if (pos == -1)
				break ;
			push_to_b(backpack, totebag, pos);
		}
		chunk++;
	}
}

void	algorithm_medium(t_stack *backpack, t_stats *totebag)
{
	t_c	c;

	if (backpack->len_a <= 1)
		return ;
	replace_with_ranks(backpack);
	c.size = ft_sqrt(backpack->len_a);
	if (c.size == 0)
		return ;
	c.max = (backpack->len_a + c.size - 1) / c.size;
	process_chunk(backpack, totebag, &c);
	empty_b_to_a(backpack, totebag);
}
