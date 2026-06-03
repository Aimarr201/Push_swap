/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:37:50 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/03 14:06:56 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_isnum(char *str)
{
	char	*tmp;

	if (!str || !*str)
		ft_error();
	tmp = str;
	if ((*tmp == '-' || *tmp == '+'))
	{
		if (*(tmp + 1) < '0' || *(tmp + 1) > '9')
			ft_error();
		tmp++;
	}
	while (*tmp)
	{
		if (*tmp < '0' || *tmp > '9')
			ft_error();
		tmp++;
	}
}

void	ft_has_duplicates(t_stack *backpack)
{
	int	i;
	int	j;

	i = 0;
	while (i < backpack->len_a)
	{
		j = i + 1;
		while (j < backpack->len_a)
		{
			if (backpack->stack_a[i] == backpack->stack_a[j])
				ft_error_free(backpack);
			j++;
		}
		i++;
	}
}
