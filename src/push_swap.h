/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:35:19 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/30 18:55:01 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
}		t_stack;

typedef struct s_stats
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total_ops;
	float	disorder;
	int		bench_flag;
	int		algorithm_flag;
}			t_stats;

/* error.c */
void	ft_error(void);
void	ft_error_free(t_stack *backpack);

/* push.c */
void	pa(t_stack *backpack);
void	pb(t_stack *backpack);

/* swap.c */
void	sa(t_stack *backpack);
void	sb(t_stack *backpack);
void	ss(t_stack *backpack);

/* rotate.c */
void	ra(t_stack *backpack);
void	rb(t_stack *backpack);
void	rr(t_stack *backpack);

/* rev_rotate.c */
void	rra(t_stack *backpack);
void	rrb(t_stack *backpack);
void	rrr(t_stack *backpack);

/* utils.c */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str);
void	ft_isnum(char *str);
long	ft_atoi(const char *str);
void	ft_has_duplicates(t_stack *backpack);

/* free.c */
void	ft_free_arrays(t_stack *backpack);

/* init.c */
void	init_back(t_stack *backpack, int size, int i, int argc, char **argv);

/* disorder.c */
float	compute_disorder(t_stack *backpack, t_stats *totebag);

/* push_swap.c */
int		ft_validate_flag(char *flag);
void	parse_args(int argc, char *argv[], t_stack *backpack, t_stats *totebag);

#endif
