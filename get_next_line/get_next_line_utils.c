/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:37 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/07 16:15:31 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strcat(str, s2);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	unsigned char	testc;

	str = (unsigned char *)s;
	testc = (unsigned char) c;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i] != testc)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

size_t	malloc_size(char const *s1, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	while (s1[start] && size < len)
	{
		size++;
		start++;
	}
	return (size);
}

char	*ft_substr(char const *s1, int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	size;

	if (!s1)
		return (NULL);
	if (start > ft_strlen(s1))
		return (ft_strdup(""));
	size = malloc_size(s1, start, len);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
