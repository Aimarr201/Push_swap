/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:19:34 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/01 17:37:52 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *backpack, t_stats *totebag)
{
	int	tmp;

	if (backpack->len_a < 2)
		return ;
	tmp = backpack->stack_a[0];
	backpack->stack_a[0] = backpack->stack_a[1];
	backpack->stack_a[1] = tmp;
	totebag->sa++;
	totebag->total_ops++;
	ft_putstr("sa\n");
}

void	sb(t_stack *backpack, t_stats *totebag)
{
	int	tmp;

	if (backpack->len_b < 2)
		return ;
	tmp = backpack->stack_b[0];
	backpack->stack_b[0] = backpack->stack_b[1];
	backpack->stack_b[1] = tmp;
	totebag->sb++;
	totebag->total_ops++;
	ft_putstr("sb\n");
}

void	ss(t_stack *backpack, t_stats *totebag)
{
	int	tmp;

	if (backpack->len_a >= 2)
	{
		tmp = backpack->stack_a[0];
		backpack->stack_a[0] = backpack->stack_a[1];
		backpack->stack_a[1] = tmp;
	}
	if (backpack->len_b >= 2)
	{
		tmp = backpack->stack_b[0];
		backpack->stack_b[0] = backpack->stack_b[1];
		backpack->stack_b[1] = tmp;
	}
	totebag->ss++;
	totebag->total_ops++;
	ft_putstr("ss\n");
}
