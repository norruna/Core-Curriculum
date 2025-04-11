/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:33:21 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:36:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
const char *str = "hello thzre";
	char c = 'z';

//        printf("Test case %d:\n", i + 1);
        printf("str: \"%s\", to_find: \"%c\"\n", str, c);
        printf("ft_strchr : %s\n", ft_strchr(str, c));
        printf("strchr : %s\n", strchr(str, c));
        printf("\n");


    return 0;
}*/
