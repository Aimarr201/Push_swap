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

 
static void	rev_rotate(int *stack, int len)
{
	int	tmp;
	int	i;
 
	tmp = stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}
 
void	rra(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_a < 2)
		return ;
	rev_rotate(backpack->stack_a, backpack->len_a);
	totebag->rra++;
	totebag->total_ops++;
	ft_putstr("rra\n");
}
 
void	rrb(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_b < 2)
		return ;
	rev_rotate(backpack->stack_b, backpack->len_b);
	totebag->rrb++;
	totebag->total_ops++;
	ft_putstr("rrb\n");
}
 
void	rrr(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_a >= 2)
		rev_rotate(backpack->stack_a, backpack->len_a);
	if (backpack->len_b >= 2)
		rev_rotate(backpack->stack_b, backpack->len_b);
	totebag->rrr++;
	totebag->total_ops++;
	ft_putstr("rrr\n");
}
