/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:33:40 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:36:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && j < size - 1)
	{
		dst[i] = src[i];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
