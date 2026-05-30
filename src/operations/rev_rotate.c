/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 19:16:45 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/30 20:01:49 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stacks(int **stack, int len)
{
	int	i;
	int	tmp;

	tmp = stack[len - 1];
	i = len;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
	}
}
void	rra(t_stack *backpack, t_stats *totebag)
{
	int	i;
	int	tmp;

	if (backpack->len_a < 2)
		return ;
	tmp = backpack->stack_a[backpack->len_a - 1];
	i = backpack->len_a - 1;
	while (i > 0)
	{
		backpack->stack_a[i] = backpack->stack_a[i - 1];
		i--;
	}
	backpack->stack_a[0] = tmp;
	totebag->rra++;
	totebag->total_ops++;
	ft_putstr("rra\n");
}

void	rrb(t_stack *backpack, t_stats *totebag)
{
	int	i;
	int	tmp;

	if (backpack->len_b < 2)
		return ;
	tmp = backpack->stack_b[backpack->len_b - 1];
	i = backpack->len_b - 1;
	while (i > 0)
	{
		backpack->stack_b[i] = backpack->stack_b[i - 1];
		i--;
	}
	backpack->stack_b[0] = tmp;
	totebag->rrb++;
	totebag->total_ops++;
	ft_putstr("rrb\n");
}

void	rrr(t_stack *backpack, t_stats *totebag)
{
	int	i;
	int	tmp;

	if (backpack->len_a >= 2)
	{
		tmp = backpack->stack_a[backpack->len_a - 1];
		i = backpack->len_a;
		while (--i > 0)
			backpack->stack_a[i] = backpack->stack_a[i - 1];
		backpack->stack_a[0] = tmp;
	}
	if (backpack->len_b >= 2)
	{
		tmp = backpack->stack_b[backpack->len_b - 1];
		i = backpack->len_b;
		while (--i > 0)
			backpack->stack_b[i] = backpack->stack_b[i - 1];
		backpack->stack_b[0] = tmp;
	}
	totebag->rrr++;
	totebag->total_ops++;
	ft_putstr("rrr\n");
}
