/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:36:37 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/11 13:11:10 by mayahiao         ###   ########.fr       */
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


t_stack *parse_stack(char **argv);
void	ft_freestack(t_stack **stack);
void	ft_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_newnode(int value);
long    ft_atol(const char *str);
int str_check(char *str);
int arg_check(char **str);


#endif
