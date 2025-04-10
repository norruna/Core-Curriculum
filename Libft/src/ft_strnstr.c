/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:24:08 by mayahiao          #+#    #+#             */
/*   Updated: 2025/02/25 14:28:05 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			temp = i;
			j = 0;
			while (little[j] != '\0' && big[temp] == little[j] && (i + j) < len)
			{
				++j;
				++temp;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		++i;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
    char *test_cases[][2] = {
        {"blablaHelloblabla", "blaHel"},
        {"blablaHelloblabla", "hola"},
        {"Hello world", "world"},
        {"Hello world", "World"},
        {"", ""},
        {"", "Hello"},
        {"Hello", ""},
        {"abcdabc", "abc"},
        {"abcdabc", "abcd"},
        {"abcdabc", "dabc"}
    };

    for (int i = 0; i < 10; i++)
    {
        char *str = test_cases[i][0];
        char *to_find = test_cases[i][1];
        printf("Test case %d:\n", i + 1);
        printf("str: \"%s\", to_find: \"%s\"\n", str, to_find);
        printf("ft_strstr : %s\n", ft_strnstr(str, to_find, 9));
        //printf("strstr : %s\n", strnstr(str, to_find, 5));
        printf("\n");
    }

    return 0;
}*/
