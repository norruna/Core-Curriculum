/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:33:47 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/19 12:18:37 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	char			*result;

	str = (char *)s;
	result = (char *) malloc ((ft_strlen(str) + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*char upper(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = 32;
	return (c);
}

int	main(void)
{
	char *res;

	res = ft_strmapi("0123456789",upper);
	printf("the resulting string is : %s\n",res);
	free(res);
	return (0);
}
*/
