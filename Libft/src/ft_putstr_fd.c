/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:28:26 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:36:28 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd (s[i], fd);
		i++;
	}
}

/*int main(void)
{
    char *str;
    str = "hellofdfdfdorld";

    ft_putstr(str);
    return (0);
}
*/
