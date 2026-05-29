/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:00:53 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/28 18:32:45 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float    compute_disorder(int *array, int size)
{
    int    mistakes;
    int    posible_combinations;
    int    i;
    int    j;

    if (size <= 1)
        return (0.0f);
    mistakes = 0;
    posible_combinations = 0;
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            posible_combinations++;
            if (array[i] > array[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return ((float)mistakes / (float)posible_combinations);
}
