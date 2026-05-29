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

char	push_swap(int argc[], char *argv[])
{
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == '-')
		ft_validate_flags(argv[1]);



	if (ft_strcmp(argv[1], "--simple"))
		algorithm_simple();
	if (ft_strcmp(argv[1], "--medium"))
		algorithm_medium();
	if (ft_strcmp(argv[1], "--complex"))
		algorithm_complex();
	algorithm_adaptative();
}

int	ft_get_numers(char *argv[])
{

}

void	ft_validate_flags(char *argv[])
{
	if (ft_strcmp(*argv, "--simple"))
		return (0);
	if (ft_strcmp(*argv, "--medium"))
		return (0);
	if (ft_strcmp(*argv, "--complex"))
		return (0);
	if (ft_strcmp(*argv,"--adaptative"))
		return (0);
	ft_error();
}
