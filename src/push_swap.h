/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:35:19 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/29 18:56:05 by amendibi         ###   ########.fr       */
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

/* utils.c */
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);
void	ft_isnum(char *str);
int	ft_atoi(const char *str);

/* free.c */
void	ft_free_arrays(t_stack *backpack);


#endif
