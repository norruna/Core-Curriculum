/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:58:49 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/15 18:45:42 by mayahiao         ###   ########.fr       */
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

int	find_position(t_stack *a, int index)
{
	int pos = 0;
	while (a)
	{
		if (a->index == index)
			return pos;
		a = a->next;
		pos++;
	}
	return -1;
}

void	push_index_to_b(t_stack **a, t_stack **b, int index)
{
	int pos;
	int size;

	while (1)
	{
		pos = find_position(*a, index);
		if (pos == 0)
			break;

		size = stack_size(*a);

		if (pos <= size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
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
		return;
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
	push_index_to_b(a, b, 0);
	push_index_to_b(a, b, 1);
	sort_three(a);
	pa(a, b);
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

/* void	radix_sort(t_stack **a, t_stack **b)
{
	int bits;
	int i;
	int j;
	
	if (!a || !*a)
		return;
	int	 size;
	bits = get_max_bits(*a);
	 printf("Max bits: %d\n", bits);  // Debug: Print number of bits to be processed
	i = 0;
	while (i < bits)
	{
		j = 0;
		size = stack_size(*a);
		 printf("Processing bit: %d\n", i);  // Debug: Show which bit we are processing

		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
} */

void	radix_sort(t_stack **a, t_stack **b)
{
	int max_index;
	int bits;
	int i;

	if (!a || !*a)
		return;

	// Find max index
	t_stack *tmp = *a;
	max_index = 0;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}

	// Number of bits needed
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;

	for (i = 0; i < bits; i++)
	{
		int processed = 0;
		int total = stack_size(*a);

		while (processed < total)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			processed++;
		}

		while (*b)
			pa(a, b);
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
