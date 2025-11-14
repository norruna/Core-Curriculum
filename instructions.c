/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:46:13 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/14 17:04:18 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **container)
{
    t_stack *first;
    t_stack *second;
    if (!container || !*container || !(*container)->next)
        return;

    first = *container;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *container = second;
}

void	push(t_stack **first, t_stack **second)
{
	t_stack		*node;

	if (!first || !*first)
		return ;
	node = *first;
	*first = (*first)->next;
	if (*first)
		(*first)->prev = NULL;
	node->next = *second;
	if (*second)
		(*second)->prev = node;
	*second = node;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	last = *stack;
	while (last->next)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

