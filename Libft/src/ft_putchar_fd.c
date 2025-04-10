/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:35:12 by mayahiao          #+#    #+#             */
/*   Updated: 2025/04/11 00:33:03 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c,int fd)
{
	write(fd, &c, 1);
}

/*#include <stdio.h>

int	main(void)
{
	int fd = 1;
	ft_putchar_fd('c',fd );
	return (0);

}*/
