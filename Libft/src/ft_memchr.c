/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:32:38 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:32:40 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *big;
	unsigned char little;
	size_t	i;
	if (!s)
		return (0);
	big = (unsigned char *)s;
	little = (unsigned char) c;
	i = 0;
	
	while (i < n)
	{
		if (little == big[i])
			return ((void *)&big[i]);
		i++;
	}
	return (0);
}

