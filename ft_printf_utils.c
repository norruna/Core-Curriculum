/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:19:33 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/06 18:22:30 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(va_list args, int c)
{
	int		count;
	char	*str;
	char	character;

	count = 0;
	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
		{
			count += write(1, str, 1);
			str++;
		}
	}
	if (c == 'c')
	{
		character = (char)va_arg(args, int);
		count += write(1, &character, 1);
	}
	if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

void	ft_putnbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	c = n % 10 + '0';
	*count += write(1, &c, 1);
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	char	c;

	if (n > 9)
		ft_putnbr_unsigned(n / 10, count);
	c = n % 10 + '0';
	*count += write(1, &c, 1);
}

int	write_number(va_list args, int c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), &count);
	return (count);
}

int	write_hexa(va_list args, int c)
{
	unsigned int	num;
	char			*tab;
	char			buffer[16];
	int				i;
	int				count;

	num = va_arg(args, unsigned int);
	count = 0;
	i = 0;
	if (c == 'x')
		tab = "0123456789abcdef";
	if (c == 'X')
		tab = "0123456789ABCDEF";
	if (num == 0)
		return (write(1, "0", 1));
	while (num != 0)
	{
		buffer[i++] = tab[num % 16];
		num /= 16;
	}
	while (i > 0)
		count += write(1, &buffer[--i], 1);
	return (count);
}
