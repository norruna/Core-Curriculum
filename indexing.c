/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:19:59 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/17 04:44:21 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_values(t_stack *a, int *arr)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
}

void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}

void	assign_indexes(t_stack *a, int *arr, int size)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size && arr[i] != tmp->value)
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	indexing(t_stack *a)
{
	int		size;
	int		*arr;

	size = stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	copy_values(a, arr);
	bubble_sort_array(arr, size);
	assign_indexes(a, arr, size);
	free(arr);
}
