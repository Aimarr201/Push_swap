/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendibi <amendibi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:35:19 by amendibi          #+#    #+#             */
/*   Updated: 2026/05/28 20:47:12 by amendibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*push.c*/
void	pa(t_stack *backpack);
void	pb(t_stack *backpack);
