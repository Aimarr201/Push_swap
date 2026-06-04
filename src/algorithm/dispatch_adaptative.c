/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_adaptative.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:47:15 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/04 21:25:07 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_adaptative(t_stack *backpack, t_stats *totebag)
{
	if (backpack->len_a == 2)
		sort_tho(backpack, totebag);
	else if (backpack->len_a == 3)
		sort_three(backpack, totebag);
	else if (backpack->len_a <= 5)
		sort_five(backpack, totebag);
	else
	{
		if (totebag->disorder < 0.2)
			algorithm_simple(backpack, totebag);
		else if (totebag->disorder < 0.5)
			algorithm_medium(backpack, totebag);
		else
			algorithm_complex(backpack, totebag);
	}
}
