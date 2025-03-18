/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:53:02 by mayahiao          #+#    #+#             */
/*   Updated: 2025/02/21 22:53:04 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dest[100]= "";
	char	src[] = "bldfsdgfgdfgdfdsfsdfsfgaadsf";
	char	*res = "" ;
	res = strncpy(dest,src,5);
	//res = ft_strncpy(dest,src,5);
	printf("%s\n",dest);
	return(0);
	
}*/
