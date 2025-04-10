/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:32:47 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:32:49 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dst;
	const unsigned char *source;
	size_t	i;

	i = 0;
	dst = dest;
	source = src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

