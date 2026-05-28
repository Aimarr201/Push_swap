/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:29:03 by luciamar          #+#    #+#             */
/*   Updated: 2026/05/28 18:32:44 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arrays(t_stacks *backpack)
{
	if (backpack->stack_a)
	{
		free(backpack->stack_a);
		backpack->stack_a = NULL;
	}
	if (backpack->array_b)
	{
		free(backpack->stack_b);
		backpack->stack_b = NULL;
	}
}
