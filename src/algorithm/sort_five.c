/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciamar <luciamar@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 21:35:05 by luciamar          #+#    #+#             */
/*   Updated: 2026/06/04 21:35:05 by luciamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *backpack, t_stats *totebag)
{
	int	pos;

	while (backpack->len_a > 3)
	{
		pos = find_min_pos(backpack);
		move_min_to_top(backpack, totebag, pos);
		pb(backpack, totebag);
	}
	sort_three(backpack, totebag);
	while (backpack->len_b > 0)
		pa(backpack, totebag);
}
