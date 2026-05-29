/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:43:19 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/29 16:34:23 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *backpack)
{
	int	i;

	if(backpack->len_a < 1)
		return ;
	i = backpack->len_b ;
	while (i > 0)
	{
 		backpack->stack_b[i] = backpack->stack_b[i - 1];
		i--;
 	}
	backpack->stack_b[0] = backpack->stack_a[0];
	backpack->len_b++;
	i = 0;
	while (i < backpack->len_a - 1)
	{
		backpack->stack_a[i] = backpack->stack_a[i + 1];
		i++;
	}
	backpack->len_a--;
	ft_putstr("pb\n", 1);
}

void	pa(t_stack *backpack)
{
	int	i;

	if(backpack->len_b < 1)
		return ;
	i = backpack->len_a ;
	while (i > 0)
	{
 		backpack->stack_a[i] = backpack->stack_a[i - 1];
		i--;
 	}
	backpack->stack_a[0] = backpack->stack_b[0];
	backpack->len_a++;
	i = 0;
	while (i < backpack->len_b - 1)
	{
		backpack->stack_b[i] = backpack->stack_b[i + 1];
		i++;
	}
	backpack->len_b--;
	ft_putstr("pa\n", 1);
}
