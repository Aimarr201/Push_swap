#include "push_swap.h"

int	count_bits_needed(int size)
{
	int	bits;
	int	max_rank;

	bits = 0;
	max_rank = size - 1;
	while ((1<< bits) <= max_rank)
		bits++;
	return (bits);
}

void	radix_pass_one_bit(t_stack *backpack, t_stats *totebag, int bit_pos, int size)
{
	while (size-- > 0)
	{
		if ((backpack->stack_a[0] >> bit_pos) & 1)
			pb(backpack, totebag);
		else
			ra(backpack, totebag);
	}
}

void	radix_sort_by_bits(t_stack *backpack, t_stats *totebag, int total_bits, int size)
{
	int	bit_pos;

	bit_pos = 0;
	while (bit_pos < total_bits)
	{
		radix_pass_one_bit(backpack, totebag, bit_pos, size);
		flush_b_to_a(backpack, totebag);
		bit_pos++;
	}
}

void	algorithm_complex(t_stack *backpack, t_stats *totebag)
{
	int	total_bits;
	int size;

	replace_with_ranks(backpack);
	sie = backpack->len_a;
	total_bits = count_bits_needed(size);
	radix_sort_by_bits(backpack, totebag, total_bits, size);
}
