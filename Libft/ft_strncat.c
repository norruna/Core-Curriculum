/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:14:31 by mayahiao          #+#    #+#             */
/*   Updated: 2025/02/24 19:22:51 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
int     main(void)
{       
        char src[] = "hello there";
        char dest[] = "why hello there ";

        //strncat(dest,src,5);
        //printf("stnrcat : %s\n",dest);
        ft_strncat(dest,src,5);
        printf("ft_strncat : %s\n",dest);

        return (0);
}*/
