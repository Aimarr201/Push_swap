
#include "push_swap.h"

int	find_insertion_position(t_stack *backpack, int value)
{
	int	i;
	int position;

	position = 0;
	i = 0;
	while ( i < backpack->len_b)
	{
		if (value > backpack->stack_b[i])
			return (position);
		position++;
		i++;
	}
}

int	best_rotation_direction(int position, int stack_len)
{
	int hacia_adelante;
	int hacia_atras;

	hacia_adelante = position;
	hacia_atras = stack_len - position;
	return (hacia_adelante <= hacia_atras);
}

void	rotate_to_position(t_stack *backpack, t_stats *totebag, int position)
{
	int	i;
	int	ve_adelante;

	if (position == 0)
		return ;
	ve_adelante = best_rotation_direction(position, backpack->len_b);
	if (ve_adelante)
	{
		i = 0;
		while (i < position)
		{
			rb(backpack, totebag);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < backpack->len_b - position)
		{
			rrb(backpack, totebag);
			i++;
		}
	}
}

void	algorithm_simple(t_stack *backpack)
{
	t_stats	*totebag;
	int	i;
	int	position;

	i = 0;
	while (backpack->len_a > 0)
	{
		position = find_insert_position(backpack, backpack->stack_a[0]);
		rotate_to_position(backpack, totebag, position);
		pb(backpack, totebag);
		i++;
	}
	while (backpack->len_b > 0)
	{
		pa(backpack, totebag);
	}
	free(totebag);
}
