/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionsV2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:56:28 by mayahiao          #+#    #+#             */
/*   Updated: 2025/11/16 23:05:45 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ------------ SWAP -------------- */
void    sa(t_stack **a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);
}

void    sb(t_stack **b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);
}

void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 1);
}

/* ------------ PUSH -------------- */
void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
    ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 1);
}

/* ----------- ROTATE ------------- */
void    ra(t_stack **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}

/* -------- REVERSE ROTATE -------- */
void    rra(t_stack **a)
{
    rev_rotate(a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack **b)
{
    rev_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}
