/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:39:07 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/17 04:53:16 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_smallest(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	bring_min_to_top(a, min_index);
	pb(a, b);
}

void	bring_min_to_top(t_stack **a, int min_index)
{
	int	size;
	int	rot;
	int	i;

	size = stack_size(*a);
	rot = count_rotations(*a, min_index);
	if (rot <= size / 2)
	{
		i = 0;
		while (i++ < rot)
			ra(a);
	}
	else
	{
		i = 0;
		while (i++ < size - rot)
			rra(a);
	}
}

int	count_rotations(t_stack *a, int min_index)
{
	int		rot;
	t_stack	*tmp;

	rot = 0;
	tmp = a;
	while (tmp->index != min_index)
	{
		rot++;
		tmp = tmp->next;
	}
	return (rot);
}

int	find_min_index(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	tmp = a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	push_count;
	int	size;

	size = stack_size(*a);
	if (size == 5)
		push_count = 2;
	else
		push_count = 1;
	while (push_count > 0)
	{
		pb_smallest(a, b);
		push_count--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
