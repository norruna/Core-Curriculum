/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:37:45 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/19 12:18:38 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
int main(void)
{
    char *str = "HELLO NELLY";
    char *str1 = "";
    char *str2 = "BONJOUR";
    
    int i,i1,i2;
    i = 0;
    i1 = 0;
    i2 = 0;
    i = ft_strlen(str);
    i1 = ft_strlen(str1);
    i2 =ft_strlen(str2);
    printf ("str = %d, str1 = %d, str3 = %d",i,i1,i2);
}*/
