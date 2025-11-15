/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:08 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/15 17:23:30 by mayahiao         ###   ########.fr       */
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
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

//added as extra measure to make sure its freed so no leaks *hopefully* *stack = NULL
void	ft_freestack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
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
//https://www.geeksforgeeks.org/dsa/program-check-array-sorted-not-iterative-recursive/

int	is_sorted(char *array, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (array[i - 1] > array[i])
			return (0);
	}
	return (1);
}
/*parse into array, sort array, save indexes used bubble sort*/
void	indexing(t_stack *a)
{
	if (!a)
		return ;
	int size = stack_size(a);
	if (size == 0)
		return ;
	int *array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	int	i = 0;
	t_stack *temp_stack = a;
    while (temp_stack)
    {
        array[i] = temp_stack->value;
        temp_stack = temp_stack->next;
        i++;
    }
	int sorted = 0;
	i = 1;
	while (sorted == 0)
	{
		sorted = 1;
		while (i < size)
		{
			if (array[i] < array[i - 1])
			{
				int temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
	temp_stack = a;
	while (temp_stack)
	{
		
			i = 0;
			while (array[i] != temp_stack->value)
				i++;
			temp_stack->index = i;
			temp_stack = temp_stack->next;
	}
	free(array);
}

t_stack *parse_stack(char **argv)
{
	t_stack	*a;
	long	value;
	int		i;

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
