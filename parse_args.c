/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:30:08 by nellys-simu       #+#    #+#             */
/*   Updated: 2025/11/10 17:01:20 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdio.h> //printf testing


typedef struct s_node
{
    int     value;
    void    *next;
}   t_node;


typedef struct s_stack
{
	int             size;
	t_node	*top_element;

}	t_stack;