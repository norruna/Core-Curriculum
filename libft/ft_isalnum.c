/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 23:15:39 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/19 12:18:55 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	int res = 0;
	char *str1 = "AZhello";
	char *str2 = "";
	char *str3 = "05445";

	res = ft_str_is_numeric(str1);
	printf(" str1 : %d \n",res);
	res = ft_str_is_numeric(str2);
	printf(" str2 : %d \n",res);
	res = ft_str_is_numeric(str3);
	printf(" str3 : %d \n",res);
	return (0);
}*/
