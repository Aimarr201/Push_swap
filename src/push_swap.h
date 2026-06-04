/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:35:19 by amendibi          #+#    #+#             */
/*   Updated: 2026/06/04 20:41:14 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

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

typedef struct s_chunk
{
	int	size;
	int	max;
	int	how_many;
}		t_c;

typedef struct s_radix
{
	int	size;
	int	bit_pos;
	int	total_bits;
}		t_r;

/* push.c */
void	pa(t_stack *backpack, t_stats *totebag);
void	pb(t_stack *backpack, t_stats *totebag);

/* swap.c */
void	sa(t_stack *backpack, t_stats *totebag);
void	sb(t_stack *backpack, t_stats *totebag);
void	ss(t_stack *backpack, t_stats *totebag);

/* rotate.c */
void	ra(t_stack *backpack, t_stats *totebag);
void	rb(t_stack *backpack, t_stats *totebag);
void	rr(t_stack *backpack, t_stats *totebag);

/* rev_rotate.c */
void	rra(t_stack *backpack, t_stats *totebag);
void	rrb(t_stack *backpack, t_stats *totebag);
void	rrr(t_stack *backpack, t_stats *totebag);

/* error_and_free.c */
void	ft_free_arrays(t_stack *backpack);
void	ft_free_back_and_tote(t_stack *backpack, t_stats *totebag);
void	ft_error(void);
void	ft_error_free(t_stack *backpack);

/* utils.c */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str);
void	ft_isnum(char *str);
void	ft_has_duplicates(t_stack *backpack);

/* atoi.c */
int		ft_atoi(const char *str);

/* init.c */
void	init_back(t_stack *backpack, int start, int argc, char **argv);
void	init_totebag(t_stats *totebag);

/* disorder.c */
void	compute_disorder(t_stack *backpack, t_stats *totebag);

/* push_swap.c */
void	launch_algorithm(t_stack *backpack, t_stats *totebag);
int		main(int argc, char *argv[]);
void	parse_args(int argc, char **argv, t_stack *backpack, t_stats *totebag);
void	ft_validate_flag(t_stats *totebag, int start, char **argv);

/* dispatch_adaptative.c */
void	sort_two(t_stack *backpack, t_stats *totebag);
void	sort_three(t_stack *backpack, t_stats *totebag);
int	find_min_pos(t_stack *backpack);
void	move_min_to_top(t_stack *backpack, t_stats *totebag, int pos);
void	dispatch_adaptative(t_stack *backpack, t_stats *totebag);

/*sort_five.c*/
void	sort_five(t_stack *backpack, t_stats *totebag);

/* print_bench.c */
void	ft_print_bench(t_stats *totebag);
void	ft_print_disorder(float disorder);
void	ft_print_strat(t_stats *totebag);
void	ft_print(char const *str, ...);
void	ft_printnbr(int nbr, int is_last);

/*sort_simple.c*/
void	smallest_to_b(t_stack *backpack, t_stats *totebag);
void	comeback_to_a(t_stack *backpack, t_stats *totebag);
void	algorithm_simple(t_stack *backpack, t_stats *totebag);

/*sort_medium.c*/
void	push_to_b(t_stack *backpack, t_stats *totebag, int pos);
void	empty_b_to_a(t_stack *backpack, t_stats *totebag);
void	process_chunk(t_stack *backpack, t_stats *totebag, t_c *chunk);
void	algorithm_medium(t_stack *backpack, t_stats *totebag);

/* sort_medium_utils.c */
int		ft_sqrt(int nb);
void	replace_with_ranks(t_stack *backpack);
int		find_closest_chunk_element(t_stack *backpack, t_c *chunk);
int		find_max_in_b(t_stack *backpack);

/*sort_complex.c*/
void	count_bits_needed(t_r *rdx);
void	radix_pass_one_bit(t_stack *backpack, t_stats *totebag, t_r *rdx);
void	flush_b_to_a(t_stack *backpack, t_stats *totebag);
void	radix_sort_by_bits(t_stack *backpack, t_stats *totebag, t_r *rdx);
void	algorithm_complex(t_stack *backpack, t_stats *totebag);

#endif
