/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:07:38 by mayahiao          #+#    #+#             */
/*   Updated: 2025/05/19 12:18:56 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

/*#include <stdio.h>

int main(void)
{
    const char *test_cases[] = {
        "42",
        "   \n\r\t-42",
        "	4193 with words",
        "words and 987",
        "-91283472332",
        "2147483647",
        "-2147483648",
        "0",
        "+123",
        "  +00123",
		"  ---+--+1234ab567",
        NULL
    };

    for (int i = 0; test_cases[i] != NULL; i++)
    {
        printf("Test case: \"%s\"\n", test_cases[i]);
        printf("ft_atoi: %d\n", ft_atoi(test_cases[i]));
        printf("atoi: %d\n", atoi(test_cases[i]));
        printf("\n");
    }

    return 0;
}*/
