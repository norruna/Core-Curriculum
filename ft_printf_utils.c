/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:52:07 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/04 17:21:22 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(va_list args, int c, int i)
{
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	i = i + 2;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		ft_putchar_fd(c, fd);
	}
}
void	ft_putnbr_unsigned_fd(int n, int fd)
{
	char	c;

	c = 0;
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		ft_putchar_fd(c, fd);
	}
}

int	write_number(va_list args, int c, int i)
{
	if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	i = i + 2;
	return (i);
}