/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:32:52 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/19 12:18:44 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src1;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *) dest;
	src1 = (const unsigned char *)src;
	if (dst > src1 && dst < src1 + n)
	{
		dst += n;
		src1 += n;
		while (n--)
			*(--dst) = *(--src1);
	}
	else
	{
		while (n--)
			*dst++ = *src1++;
	}
	return (dest);
}
