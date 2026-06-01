/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:15:13 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/01 18:31:25 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_validate_flag(t_stats *totebag, int start, char **argv)
{
	if (ft_strcmp(argv[start], "--simple")
		|| ft_strcmp(argv[start], "--medium")
		|| ft_strcmp(argv[start], "--complex")
		|| ft_strcmp(argv[start], "--adaptative"))
	{
		if (totebag->algorithm_flag != 0)
			ft_error();
		if (ft_strcmp(argv[start], "--simple"))
			totebag->algorithm_flag = 1;
		else if (ft_strcmp(argv[start], "--medium"))
			totebag->algorithm_flag = 2;
		else if (ft_strcmp(argv[start], "--complex"))
			totebag->algorithm_flag = 3;
		else
			totebag->algorithm_flag = 4;
	}
	else if (ft_strcmp(argv[start], "--bench"))
	{
		if (totebag->bench_flag != 0)
			ft_error();
		totebag->bench_flag = 1;
	}
	else
		ft_error();
}

void	parse_args(int argc, char **argv, t_stack *backpack, t_stats *totebag)
{
	int	i;
	int	nums;
	int	start;

	init_totebag(totebag);
	start = 1;
	while (argv[start][0] == '-' && argv[start][1] == '-')
	{
		ft_validate_flag(totebag, start, argv);
		start++;
	}
	if (argc < start + 1) // verificar comportamiento
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
	backpack = malloc(sizeof(t_stack));
	totebag = malloc(sizeof(t_stats));
	if (!backpack || !totebag)
		ft_error();
	parse_args(argc, argv, backpack, totebag);
	compute_disorder(backpack, totebag);
	if (totebag->algorithm_flag)
	{
		if (totebag->algorithm_flag == 1)
			algorithm_simple(backpack, totebag);
		else if (totebag->algorithm_flag == 2)
			algorithm_medium(backpack, totebag);
		else if (totebag->algorithm_flag == 3)
			algorithm_complex(backpack, totebag);
	}
	else
		dispatch_adaptative(backpack, totebag);
	ft_free_back_and_tote(backpack, totebag);
}
