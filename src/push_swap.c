/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:15:13 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/29 19:21:22 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validate_flag(char *flag)
{
	if (ft_strcmp(flag, "--simple"))
		return (1);
	if (ft_strcmp(flag, "--medium"))
		return (2);
	if (ft_strcmp(flag, "--complex"))
		return (3);
	if (ft_strcmp(flag, "--adaptative"))
		return (4);
	ft_error();
}

void	parse_args(int argc, char *argv[], t_stack *backpack, t_stats *totebag)
{
	int	i;
	int	nums;
	int	start;

	if (argc < 2)
		ft_error();
	init_totebag(&totebag);
	start = 1;
	if (argv[1][0] == '-' && argv[1][1] == '-')
	{
		totebag->algorithm_flag = ft_validate_flag(argv[1]);
		start = 2;
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
	init_backpack(backpack, nums, start, argc, argv);
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
			algorithm_simple(&backpack);
		else if (totebag->algorithm_flag == 2)
			algorithm_medium(&backpack);
		else if (totebag->algorithm_flag == 3)
			algorithm_complex(&backpack);
		else if (totebag->algorithm_flag == 4) // omitible
			dispatch_adaptative(&backpack);
	}
	else
		dispatch_adaptative(&backpack);
	ft_error_free(&backpack); // ns si es colada
}
