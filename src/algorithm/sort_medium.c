/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:00:00 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/02 00:00:00 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_chunk_size(int n)
{
	int	s;

	s = 1;
	while (s * s < n)
		s++;
	return (s);
}

static void	bubble_sort_copy(int *arr, int n)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_ranks(int *ranks, int *sorted, int *stack_a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (sorted[j] != stack_a[i])
			j++;
		ranks[i] = j;
		i++;
	}
}

static int	*build_ranks(t_stack *backpack)
{
	int	*sorted;
	int	*ranks;
	int	n;
	int	i;

	n = backpack->len_a;
	sorted = malloc(sizeof(int) * n);
	ranks = malloc(sizeof(int) * n);
	if (!sorted || !ranks)
		ft_error();
	i = -1;
	while (++i < n)
		sorted[i] = backpack->stack_a[i];
	bubble_sort_copy(sorted, n);
	assign_ranks(ranks, sorted, backpack->stack_a, n);
	free(sorted);
	return (ranks);
}

static int	find_in_a(t_stack *backpack, int *ranks, int cmin, int cmax)
{
	int	i;

	i = 0;
	while (i < backpack->len_a)
	{
		if (ranks[i] >= cmin && ranks[i] <= cmax)
			return (i);
		i++;
	}
	return (-1);
}

static void	shift_ranks_left(int *ranks, int len)
{
	int	k;

	k = 0;
	while (k < len - 1)
	{
		ranks[k] = ranks[k + 1];
		k++;
	}
}

static void	shift_ranks_right(int *ranks, int len)
{
	int	k;

	k = len - 1;
	while (k > 0)
	{
		ranks[k] = ranks[k - 1];
		k--;
	}
}

static void	bring_a_to_top(t_stack *backpack, t_stats *totebag,
				int *ranks, int pos)
{
	int	tmp;
	int	steps;

	if (pos <= backpack->len_a / 2)
	{
		while (pos-- > 0)
		{
			tmp = ranks[0];
			shift_ranks_left(ranks, backpack->len_a);
			ranks[backpack->len_a - 1] = tmp;
			ra(backpack, totebag);
		}
	}
	else
	{
		steps = backpack->len_a - pos;
		while (steps-- > 0)
		{
			tmp = ranks[backpack->len_a - 1];
			shift_ranks_right(ranks, backpack->len_a);
			ranks[0] = tmp;
			rra(backpack, totebag);
		}
	}
}

static void	push_chunk_to_b(t_stack *backpack, t_stats *totebag,
				int *ranks, int cmin, int cmax)
{
	int	pos;

	while (1)
	{
		pos = find_in_a(backpack, ranks, cmin, cmax);
		if (pos == -1)
			break ;
		bring_a_to_top(backpack, totebag, ranks, pos);
		shift_ranks_left(ranks, backpack->len_a);
		pb(backpack, totebag);
	}
}

static int	find_max_in_b(t_stack *backpack, int *b_ranks)
{
	int	max_rank;
	int	max_pos;
	int	i;

	max_rank = -1;
	max_pos = 0;
	i = 0;
	while (i < backpack->len_b)
	{
		if (b_ranks[i] > max_rank)
		{
			max_rank = b_ranks[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

static void	bring_b_to_top(t_stack *backpack, t_stats *totebag,
				int *b_ranks, int pos)
{
	int	tmp;
	int	steps;

	if (pos <= backpack->len_b / 2)
	{
		while (pos-- > 0)
		{
			tmp = b_ranks[0];
			shift_ranks_left(b_ranks, backpack->len_b);
			b_ranks[backpack->len_b - 1] = tmp;
			rb(backpack, totebag);
		}
	}
	else
	{
		steps = backpack->len_b - pos;
		while (steps-- > 0)
		{
			tmp = b_ranks[backpack->len_b - 1];
			shift_ranks_right(b_ranks, backpack->len_b);
			b_ranks[0] = tmp;
			rrb(backpack, totebag);
		}
	}
}

static int	*build_b_ranks(t_stack *backpack, int *sorted_orig, int n)
{
	int	*b_ranks;
	int	i;
	int	j;

	b_ranks = malloc(sizeof(int) * n);
	if (!b_ranks)
		ft_error();
	i = 0;
	while (i < backpack->len_b)
	{
		j = 0;
		while (sorted_orig[j] != backpack->stack_b[i])
			j++;
		b_ranks[i] = j;
		i++;
	}
	return (b_ranks);
}

static void	pull_all_to_a(t_stack *backpack, t_stats *totebag,
				int *sorted_orig, int n)
{
	int	*b_ranks;
	int	pos;

	b_ranks = build_b_ranks(backpack, sorted_orig, n);
	while (backpack->len_b > 0)
	{
		pos = find_max_in_b(backpack, b_ranks);
		bring_b_to_top(backpack, totebag, b_ranks, pos);
		shift_ranks_left(b_ranks, backpack->len_b);
		pa(backpack, totebag);
	}
	free(b_ranks);
}

static void	build_sorted_copy(int *sorted_copy, int *ranks,
				int *stack_a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		sorted_copy[ranks[i]] = stack_a[i];
		i++;
	}
}

static void	phase_one(t_stack *backpack, t_stats *totebag,
			int *ranks, int n)
{
	int	csize;
	int	nchunks;
	int	chunk;
	int	cmax;

	csize = calc_chunk_size(n);
	nchunks = (n + csize - 1) / csize;
	chunk = 0;
	while (chunk < nchunks)
	{
		cmax = (chunk + 1) * csize - 1;
		if (cmax > n - 1)
			cmax = n - 1;
		push_chunk_to_b(backpack, totebag, ranks, chunk * csize, cmax);
		chunk++;
	}
}

void	algorithm_medium(t_stack *backpack, t_stats *totebag)
{
	int	*ranks;
	int	*sorted_copy;
	int	n;

	n = backpack->len_a;
	if (n <= 1)
		return ;
	sorted_copy = malloc(sizeof(int) * n);
	if (!sorted_copy)
		ft_error();
	ranks = build_ranks(backpack);
	build_sorted_copy(sorted_copy, ranks, backpack->stack_a, n);
	phase_one(backpack, totebag, ranks, n);
	free(ranks);
	pull_all_to_a(backpack, totebag, sorted_copy, n);
	free(sorted_copy);
}