/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:22:10 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/17 04:45:18 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(char *array, int size)
{
	int	i;

	if (!array || size <= 1)
		return (0);
	i = 1;
	while (i < size)
	{
		if (array[i - 1] > array[i])
			return (0);
		i++;
	}
	return (1);
}

int	str_check(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (ft_strlen(str) == 1 && (str[0] < '0' || str[0] > '9'))
		return (0);
	else
	{
		i = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			if (!str[1] || (str[1] < '0' || str[1] > '9'))
				return (0);
			i++;
		}
		while (str[i] && (i < ((int)ft_strlen(str))))
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}

int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	arg_check(char **str)
{
	int	i;
	int	r;

	i = 0;
	while (str[i])
	{
		r = str_check(str[i]);
		if (r == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
