/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 01:48:35 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 01:48:36 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;
	
	if (*lst == NULL)
	{
		*lst = new;
		return ;	
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
