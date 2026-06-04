/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:00:00 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/04 13:25:14 by amendibi         ###   ########.fr       */
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
		while (steps-- > 0)
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
			while (max_pos-- > 0)
				rb(backpack, totebag);
		}
		else
		{
			steps = backpack->len_b - max_pos;
			while (steps-- > 0)
				rrb(backpack, totebag);
		}
		pa(backpack, totebag);
	}
}

void	process_chunk(t_stack *backpack, t_stats *totebag, t_c *chunk)
{
	int	pos;

	chunk->how_many = 0;
	while (chunk->how_many < chunk->max)
	{
		while (1)
		{
			pos = find_closest_chunk_element(backpack, chunk);
			if (pos == -1)
				break ;
			push_to_b(backpack, totebag, pos);
		}
		chunk->how_many++;
	}
}

void	algorithm_medium(t_stack *backpack, t_stats *totebag)
{
	t_c	*chunk;

	if (!totebag->disorder)
		return ;
	chunk = malloc(sizeof(t_c));
	if (!chunk)
		ft_error_free(backpack);
	if (backpack->len_a <= 1)
	{
		free(chunk);
		return ;
	}
	replace_with_ranks(backpack);
	chunk->size = ft_sqrt(backpack->len_a);
	if (chunk->size == 0)
	{
		free(chunk);
		return ;
	}
	chunk->max = (backpack->len_a + chunk->size - 1) / chunk->size;
	process_chunk(backpack, totebag, chunk);
	empty_b_to_a(backpack, totebag);
	free(chunk);
}
