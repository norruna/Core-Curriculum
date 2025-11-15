/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:36:37 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/15 15:34:36 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h> //printftest
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


t_stack		*parse_stack(char **argv);
t_stack		*ft_newnode(int value);
void		ft_freestack(t_stack **stack);
void		ft_add_back(t_stack **stack, t_stack *new);
int			str_check(char *str);
int			arg_check(char **str);
long		ft_atol(const char *str);

/*instructions*/
void		swap(t_stack **container);
void		push(t_stack **first, t_stack **second);
void		rotate(t_stack **container);
void		rev_rotate(t_stack **stack);

/*insctructionsV2*/
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);


/*sorting*/
void		sorting(t_stack **a, t_stack **b);
void		radix_sort(t_stack **a, t_stack **b);
int			stack_size(t_stack *a);
int			get_max(t_stack *a);
void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);

void		indexing(t_stack *a);
#endif
