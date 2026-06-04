/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:21:08 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/04 13:21:34 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_back(t_stack *backpack, int size, int i, int argc, char **argv)
{
	backpack->stack_a = malloc(sizeof(int) * size);
	backpack->stack_b = malloc(sizeof(int) * size);
	if (!backpack->stack_a || !backpack->stack_b)
		ft_error_free(backpack);
	backpack->len_a = 0;
	backpack->len_b = 0;
	while (i < argc)
	{
		backpack->stack_a[backpack->len_a] = (int)ft_atoi(argv[i]);
		backpack->len_a++;
		i++;
	}
	ft_has_duplicates(backpack);
}

void	init_totebag(t_stats *totebag)
{
	totebag->sa = 0;
	totebag->sb = 0;
	totebag->ss = 0;
	totebag->pa = 0;
	totebag->pb = 0;
	totebag->ra = 0;
	totebag->rb = 0;
	totebag->rr = 0;
	totebag->rra = 0;
	totebag->rrb = 0;
	totebag->rrr = 0;
	totebag->total_ops = 0;
	totebag->disorder = 0.0f;
	totebag->bench_flag = 0;
	totebag->algorithm_flag = 0;
}
