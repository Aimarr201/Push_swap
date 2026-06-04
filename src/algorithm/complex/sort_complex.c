/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciamar <luciamar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:06:56 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/04 20:11:38 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_bits_needed(t_r *rdx)
{
	int	bits;
	int	max_rank;

	bits = 0;
	max_rank = rdx->size - 1;
	while ((1 << bits) <= max_rank)
		bits++;
	rdx->total_bits = bits;
}

void	radix_pass_one_bit(t_stack *backpack, t_stats *totebag, t_r *rdx)
{
	int	count;

	count = backpack->len_a;
	while (count-- > 0)
	{
		if ((backpack->stack_a[0] >> rdx->bit_pos) & 1)
			ra(backpack, totebag);
		else
			pb(backpack, totebag);
	}
}

void	flush_b_to_a(t_stack *backpack, t_stats *totebag)
{
	while (backpack->len_b > 0)
		pa(backpack, totebag);
}

void	radix_sort_by_bits(t_stack *backpack, t_stats *totebag, t_r *rdx)
{
	rdx->bit_pos = 0;
	while (rdx->bit_pos < rdx->total_bits)
	{
		radix_pass_one_bit(backpack, totebag, rdx);
		flush_b_to_a(backpack, totebag);
		rdx->bit_pos++;
	}
}

void	algorithm_complex(t_stack *backpack, t_stats *totebag)
{
	t_r	*rdx;

	if (!totebag->disorder)
		return ;
	rdx = malloc(sizeof(t_r));
	if (!rdx)
		ft_error_free(backpack);
	replace_with_ranks(backpack);
	rdx->size = backpack->len_a;
	count_bits_needed(rdx);
	radix_sort_by_bits(backpack, totebag, rdx);
	free(rdx);
	return ;
}
