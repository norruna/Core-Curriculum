/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:52:07 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/04 18:20:41 by mayahiao         ###   ########.fr       */
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

int	write_hexa(va_list args, int c, int i)
{
	char	*lower_tab; 
	char	*upper_tab;
	int		num;

	num = va_arg(args, int);
	lower_tab = "0123456789abcdef";
	upper_tab = "0123456789ABCDEF";
	if (c == 'x' || c == 'p')
	{
		if (c == 'p')
		{
			ft_putstr_fd("0x", 1);
		}
		ft_putchar_fd(lower_tab[num / 16], 1);
		ft_putchar_fd(lower_tab[num % 16], 1);
	}
	else 
	{
		ft_putchar_fd(upper_tab[num / 16], 1);
		ft_putchar_fd(upper_tab[num % 16], 1);
	}
	i = i + 2;
	return (i);
}

