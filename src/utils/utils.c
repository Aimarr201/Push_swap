/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:37:50 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/29 19:11:12 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
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

	if (!str)
		ft_error();
	tmp = str;
	if ((*tmp == '-' || *tmp == '+') && (*tmp + 1 > '0' && *tmp + 1 < '9'))
		*tmp++;
	while (*tmp)
	{
		if (*tmp > '0' && *tmp < '9')
			*tmp++;
		else
			ft_error();
	}
}

int	ft_atoi(const char *str)
{
	int	num;
	int	negative;

	num = 0;
	negative = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (negative == 1)
		return (num * -1);
	return (num);
}
