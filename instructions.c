/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:46:13 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/13 00:04:36 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void s(t_stack **container)
{
    t_stack *first;
    t_stack *second;
    if (!container || !*container || !(*container)->next)
        return ;
    first = *container;
    second = first -> next;
    first->next = second ->next;
    if (second ->next)
        second->next = first;
    second ->prev =NULL;
    first -> prev = second;
}
void ss(t_stack **a, t_stack **b)
{
	s(a);
	s(b);
}
void	p(t_stack **first, t_stack **second)
{
	t_stack *node;

	if (!first || !*first)
		return;
	node = *first;
	*first = (*first)->next;
	if (*first)
		(*first)->prev = NULL;

	node->next = *second;
	if (*second)
		(*second)->prev = node;
	*second = node;
}

