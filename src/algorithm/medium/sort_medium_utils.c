/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciamar <luciamar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:50:39 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/04 13:08:18 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return(0);
	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

void	replace_with_ranks(t_stack *backpack)
{
	int	*tmp;
	int	i;
	int	j;

	tmp =  malloc(sizeof(int) * backpack->len_a);
	if (!tmp)
		ft_error();
	i = -1;
	while (++i < backpack->len_a)
	{
		tmp[i] = 0;
		j = -1;
		while (++j < backpack->len_a)
		{
			if (backpack->stack_a[i] > backpack->stack_a[j])
				tmp[i]++;
		}
	}
	i = -1;
	while (++i < backpack->len_a)
		backpack->stack_a[i] = tmp[i];
	free(tmp);
}
int	find_max_in_b(t_stack *backpack)
{
	int	max_pos;
	int	i;

	max_pos = 0;
	i = 1;
	while (i < backpack->len_b)
	{
		if (backpack->stack_b[i] > backpack->stack_b[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}
int	find_closest_chunk_element(t_stack *backpack, t_c *chunk)
{
	int	i;
	int	top;
	int	bot;

	top = -1;
	bot = -1;
	i = -1;
	while (++i < backpack->len_a)
	{
		if (backpack->stack_a[i] / chunk->size == chunk->how_many && top == -1)
			top = i;
	}
	i = backpack->len_a;
	while (--i >= 0)
	{
		if (backpack->stack_a[i] / chunk->size == chunk->how_many && bot == -1)
			bot = i;
	}
	if (top == -1)
		return (-1);
	if (top <= backpack->len_a - 1 - bot)
		return (top);
	return (bot);
}
