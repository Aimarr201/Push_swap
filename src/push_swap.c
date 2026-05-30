/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:15:13 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/30 19:24:55 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_validate_flag(t_stack *backpack, t_stats *totebag, int start)
{
	if (totebag->algorithm_flag == 0 || totebag->bench_flag == 0)
	{
		if (totebag->algorithm_flag == 0)
		{
			if (ft_strcmp(backpack->stack_a[start], "--simple"))
				totebag->algorithm_flag = 1;
			else if (ft_strcmp(backpack->stack_a[start], "--medium"))
				totebag->algorithm_flag = 2;
			else if (ft_strcmp(backpack->stack_a[start], "--complex"))
				totebag->algorithm_flag = 3;
			else if (ft_strcmp(backpack->stack_a[start], "--adaptative"))
				totebag->algorithm_flag = 4;
			else
				ft_error_free(&backpack, &totebag);
		}
		if (totebag->bench_flag == 0)
		{
			if (ft_strcmp(backpack->stack_a[start], "--bench"))
				totebag->bench_flag = 1;
		}
	}
	ft_error();
}

void	parse_args(int argc, char *argv[], t_stack *backpack, t_stats *totebag)
{
	int	i;
	int	nums;
	int	start;

	if (argc < 2)
		ft_error();
	init_totebag(totebag);
	start = 1;
	while (argv[start][0] == '-' && argv[start][1] == '-')
	{
		ft_validate_flag(&backpack, &totebag, start);
		start++;
	}
	if (argc < start + 1)
		ft_error();
	nums = 0;
	i = start;
	while (i < argc)
	{
		ft_isnum(argv[i]);
		nums++;
		i++;
	}
	init_back(backpack, nums, start, argc, argv);
}

int	main(int argc, char *argv[])
{
	t_stack	*backpack;
	t_stats	*totebag;

	if (argc < 2)
		ft_error();
	parse_args(argc, argv, &backpack, &totebag);
	compute_disorder(&backpack, &totebag);
	if (totebag->algorithm_flag)
	{
		if (totebag->algorithm_flag == 1)
			algorithm_simple(backpack);
		else if (totebag->algorithm_flag == 2)
			algorithm_medium(backpack);
		else if (totebag->algorithm_flag == 3)
			algorithm_complex(backpack);
	}
	else
		dispatch_adaptative(backpack);
	ft_free_back_and_tote(backpack, totebag);
}
