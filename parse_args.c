/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:08 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/14 17:37:58 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
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

long	ft_atol(const char *str) //just modified atoi to handle long numbers
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
    t_stack *a;
    long    value;
    int     i;

    i = 0;
    a = NULL;
    while (argv[i])
    {
        value = ft_atol(argv[i]);
        if (value < INT_MIN || value > INT_MAX)
            return (ft_putstr_fd("Error\n", 2), ft_freestack(&a), NULL);
        if (!check_duplicate(a, (int)value))
            return (ft_putstr_fd("Error\n", 2), ft_freestack(&a), NULL);
        ft_add_back(&a, ft_newnode((int)value));
        i++;
    }
    return (a);
}

void assign_indices(t_stack *a)
{
    t_stack *tmp1, *tmp2;
    int idx;

    tmp1 = a;
    while (tmp1)
    {
        idx = 0;
        tmp2 = a;
        while (tmp2)
        {
            if (tmp2->value < tmp1->value)
                idx++;
            tmp2 = tmp2->next;
        }
        tmp1->index = idx;
        tmp1 = tmp1->next;
    }
}
