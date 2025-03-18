/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:01:34 by mayahiao          #+#    #+#             */
/*   Updated: 2025/02/20 20:16:18 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = ' ';
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n,fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
	{
		c = n + '0';
		ft_putchar_fd(c,fd);
	}
}

/*int	main(void)
{
	int 	fd = 1;
	ft_putnbr_fd(-2147483648,fd);
	ft_putstr_fd("\n",fd);
	ft_putnbr_fd(-52,fd);
	ft_putstr_fd("\n",fd);
	ft_putnbr_fd(422,fd);
	ft_putstr_fd("\n",fd);
	return(0);
}*/
