/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:21:39 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/01 17:35:01 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *backpack, t_stats *totebag)
{
	int	tmp;
	int	i;

	if (backpack->len_a < 2)
		return;
	tmp = backpack->stack_a[0];
	i = 0;
	while (i < backpack->len_a - 1)
	{
		backpack->stack_a[i] = backpack->stack_a[i + 1];
		i++;
	}
	backpack->stack_a[backpack->len_a - 1] = tmp;
	totebag->ra++;
	totebag->total_ops++;
	ft_putstr("ra\n");
}

void	rb(t_stack *backpack, t_stats *totebag)
{
	int	tmp;
	int	i;

	if (backpack->len_b < 2)
		return;
	tmp = backpack->stack_b[0];
	i = 0;
	while (i < backpack->len_b - 1)
	{
		backpack->stack_b[i] = backpack->stack_b[i + 1];
		i++;
	}
	backpack->stack_b[backpack->len_b - 1] = tmp;
	totebag->ra++;
	totebag->total_ops++;
	ft_putstr("rb\n");
}

void	rr(t_stack *backpack, t_stats *totebag)
{
	int	tmp;
	int	i;

	if (backpack->len_a >= 2)
	{
		tmp = backpack->stack_a[0];
		i = -1;
		while (++i < backpack->len_a - 1)
			backpack->stack_a[i] = backpack->stack_a[i + 1];
		backpack->stack_a[backpack->len_a - 1] = tmp;
	}
	if (backpack->len_b >= 2)
	{
		tmp = backpack->stack_b[0];
		i = -1;
		while (++i < backpack->len_b - 1)
			backpack->stack_b[i] = backpack->stack_b[i + 1];
		backpack->stack_b[backpack->len_b - 1] = tmp;
	}
	totebag->rr++;
	totebag->total_ops++;
	ft_putstr("rr\n");
}
