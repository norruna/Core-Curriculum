/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:32:03 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:32:05 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;

	if ((int)nmemb == 0 || (int)size == 0)
		return (malloc(1));
	if (nmemb * size > SIZE_MAX || ((int)nmemb < 0 || (int)size < 0))
		return (NULL);
	result = (unsigned char *)malloc ((nmemb * size) * sizeof(unsigned char));
	if (!result)
		return (NULL);
	ft_bzero((void *)result, nmemb * size);
	return ((void *)result);	
}
