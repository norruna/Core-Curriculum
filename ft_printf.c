/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:34:54 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/06 18:35:57 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_pointer(va_list args)
{
	unsigned long long	pointer;
	char				*tab;
	char				buffer[20];
	int					i;
	int					count;

	pointer = (unsigned long long)va_arg(args, void *);
	tab = "0123456789abcdef";
	i = 0;
	count = 0;
	if (!pointer)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (pointer != 0)
	{
		buffer[i] = tab[pointer % 16];
		pointer /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		count += write(1, &buffer[i], 1);
	}
	return (count);
}

int	format_specifier(va_list args, int c)
{
	int	count;

	count = 0;
	if (c == 's' || c == 'c' || c == '%')
		count += write_string(args, c);
	else if (c == 'd' || c == 'i' || c == 'u')
		count += write_number(args, c);
	else if (c == 'x' || c == 'X')
		count += write_hexa(args, c);
	else if (c == 'p')
		count += write_pointer(args);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += format_specifier(args, str[i]);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{	
	void	*p = "example";
	int num = ft_printf("ft_printf : * s : %s\n * c : %c\n * 
		d : %d\n * u : %u\n * i : %i\n * p : %p\n * x : %x\n * X : %X\n * 
			percent : %%\n\n","HELLO WORLD",'N',42,-42,42,p,42,42 );
	printf("ft_printf number of characters : %d\n\n\n",num);
	int num1 = printf("ft_printf : * s : %s\n * c : %c\n * 
		d : %d\n * u : %u\n * i : %i\n * p : %p\n * x : %x\n * X : %X\n * 
			percent : %%\n\n","HELLO WORLD",'N',42,-42,42,p,42,42 );
	printf("printf number of characters : %d\n\n\n",num1);
	return (0);
} */
