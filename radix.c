/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:58:49 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/17 00:55:30 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int first = (*a)->value;
	int second = (*a)->next->value;
	int third = (*a)->next->next->value;

	if (first < second && second < third)
		return ;
	else if (first > second && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && first > third)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int push_count = stack_size(*a) == 5 ? 2 : 1;

	for (int k = 0; k < push_count; k++)
	{
		// Find smallest index in A
		t_stack *tmp = *a;
		int min_index = tmp->index;
		while (tmp)
		{
			if (tmp->index < min_index)
				min_index = tmp->index;
			tmp = tmp->next;
		}

		// Bring the node with min_index to top
		int rotations = 0;
		tmp = *a;
		while (tmp->index != min_index)
		{
			rotations++;
			tmp = tmp->next;
		}

		int size = stack_size(*a);
		if (rotations <= size / 2)
			for (int i = 0; i < rotations; i++)
				ra(a);
		else
			for (int i = 0; i < size - rotations; i++)
				rra(a);

		// Push smallest to B
		pb(a, b);
	}

	// Sort remaining 3 elements in A
	sort_three(a);

	// Push back from B to A
	while (*b)
		pa(a, b);
}




int	get_max_bits(t_stack *a)
{
	int max = 0;
	int bits = 0;

	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return bits;
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	bits;
	int	size;

	size = stack_size(*a);
	t_stack *temp;
	bits = get_max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			temp = *a;
			if (((temp->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

int		is_it_sorted(t_stack **container)
{
	t_stack *a;
	a = *container;

	while (a && a->next)
	{
		if (a->next->index < a->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sorting(t_stack **a, t_stack **b)
{
	int size;

	size = stack_size(*a);
	if (is_it_sorted(a))
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
