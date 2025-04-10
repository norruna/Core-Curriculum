/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:34:03 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:34:04 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	malloc_size(char const *s1, unsigned int start, size_t len)
{
	size_t	size = 0;

	while (s1[start] && size < len)
	{
		size++;
		start++;
	}
	return (size);
}

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	size;

	if (!s1)
		return (NULL);
	if (start > ft_strlen(s1))
		return (ft_strdup("")); // safer to return empty string than NULL
	size = malloc_size(s1, start, len);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size) // ✅ use size, not len
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

