/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:21:39 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/02 19:20:08 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(int *stack, int len)
{
	int	tmp;
	int	i;

	tmp = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = tmp;
}

void	ra(t_stack *backpack, t_stats *totebag)
{
	int	tmp;
	int	i;

	if (backpack->len_a < 2)
		return;
	rotate(backpack->stack_a, backpack->len_a);
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
	rotate(backpack->stack_b, backpack->len_b);
	totebag->rb++;
	totebag->total_ops++;
	ft_putstr("rb\n");
}

void	rr(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_a >= 2)
		rotate(backpack->stack_a, backpack->len_a);
	if (backpack->len_b >= 2)
		rotate(backpack->stack_b, backpack->len_b);
	totebag->rr++;
	totebag->total_ops++;
	ft_putstr("rr\n");
}
