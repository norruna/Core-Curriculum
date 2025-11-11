/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:08 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/10 18:33:19 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdio.h> //printf testing


typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_newnode(int value)
{
	t_stack	*node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return;
	if (!*stack)
	{
		*stack = new;
		return;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
void	ft_freestack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

t_stack *parse_stack(char **argv)
{
	t_stack *a = NULL;
	int i = 0;

	while (argv[i])
	{
		int value = ft_atoi(argv[i]);
		t_stack *node = ft_newnode(value);
		ft_add_back(&a, node);
		i++;
	}
	return (a);
}
