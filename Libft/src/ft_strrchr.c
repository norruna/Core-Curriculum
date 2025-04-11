/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:33:54 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:36:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	testc;

	if (!s)
		return (NULL);
	testc = (unsigned char) c;
	str = (char *)s + ft_strlen(s);
	while (*str != testc && *str != *s)
		str--;
	if (*str == testc)
		return (str);
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
const char *str = "tripouille";
	char c = 't';

//        printf("Test case %d:\n", i + 1);
        printf("str: \"%s\", to_find: \"%c\"\n", str, c);
        printf("ft_strrchr : %s\n", ft_strrchr(str, c));
        printf("strrchr : %s\n", strrchr(str, c));
        printf("\n");


    return 0;
}*/
