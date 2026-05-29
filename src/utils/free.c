/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:29:03 by luciamar          #+#    #+#             */
/*   Updated: 2026/05/29 18:52:17 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arrays(t_stack *backpack)
{
	if (backpack->stack_a)
	{
		free(backpack->stack_a);
		backpack->stack_a = NULL;

	}
	if (backpack->stack_b)
	{
		free(backpack->stack_b);
		backpack->stack_b = NULL;
	}
}
