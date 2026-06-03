/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:09:42 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/29 16:17:10 by amendibi         ###   ########.fr       */
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

void	ft_free_back_and_tote(t_stack *backpack, t_stats *totebag)
{
	ft_free_arrays(backpack);
	free(backpack);
	free(totebag);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_error_free(t_stack *backpack)
{
	ft_free_arrays(backpack);
	ft_error();
}
