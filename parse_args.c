/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:08 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/11 19:33:50 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	*stack = NULL; //added as extra measure to make sure its freed so no leaks *hopefully*
}

long	ft_atol(const char *str)
{
	int	i;
	int	sign;
	long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}
int	check_duplicate(t_stack *check, int var)
{
	t_stack *temp = check;
	while (temp)
	{
		if (temp -> value == var)
			return (0);
		temp = temp ->next;
	}
	return (1);
}

t_stack *parse_stack(char **argv)
{
	t_stack *a = NULL;
	int i = 0;

	while (argv[i])
	{
		long value = ft_atol(argv[i]);
		if (value < INT_MIN  || value > INT_MAX)
		{
			printf ("Error, value out of bound\n");
			ft_freestack(&a);
			return (NULL);
		}
		if (check_duplicate(a, (int)value) == 0)
		{
			printf("error, there is a duplicate\n");
			ft_freestack(&a);
			return (NULL);
		}
		t_stack *node = ft_newnode((int)value);
		ft_add_back(&a, node);
		i++;
	}
	return (a);
}
