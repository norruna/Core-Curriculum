/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:50:22 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:36:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i]
		&& s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
    char *test_cases[][2] = {
        {"hello", "hello"},
        {"hello", "world"},
        {"world", "hello"},
        {"", ""},
        {"", "hello"},
        {"hello", ""},
        {"abc", "abcd"},
        {"abcd", "abc"},
        {"abc", "abC"},
        {"abC", "abc"}
    };
    unsigned int n_values[] = {5, 3, 4, 0, 5, 5, 3, 4, 3, 3};

    for (int i = 0; i < 10; i++)
    {
        char *s1 = test_cases[i][0];
        char *s2 = test_cases[i][1];
        unsigned int n = n_values[i];
        printf("Test case %d:\n", i + 1);
        printf("s1: \"%s\", s2: \"%s\", n: %u\n", s1, s2, n);
        printf("ft_strncmp : %d\n", ft_strncmp(s1, s2, n));
        printf("strncmp : %d\n", strncmp(s1, s2, n));
        printf("\n");
    }

    return 0;
}*/
