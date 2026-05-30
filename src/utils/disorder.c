/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:00:53 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/28 18:32:45 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_disorder(t_stack *backpack, t_stats *totebag)
{
	int	mistakes;
	int	posible_combinations;
	int	i;
	int	j;

	mistakes = 0;
	posible_combinations = 0;
	i = 0;
	while (i < backpack->len_a)
	{
		j = i + 1;
		while (j < backpack->len_a)
		{
			posible_combinations++;
			if (backpack->stack_a[i] > backpack->stack_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	totebag->disorder = ((float)mistakes / (float)posible_combinations);
}
