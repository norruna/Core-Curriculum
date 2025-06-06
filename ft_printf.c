/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:34:54 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/06 17:26:05 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	write_pointer(va_list args)
{
	uintptr_t	ptr;
	char		*tab;
	char		buffer[20];
	int			i;
	int			count;

	ptr = (uintptr_t)va_arg(args, void *);
	tab = "0123456789abcdef";
	i = 0;
	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (ptr != 0)
	{
		buffer[i] = tab[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		count += write(1, &buffer[i], 1);
	}
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
			if (str[i] == 's' || str[i] == 'c' || str[i] == '%')
				count += write_string(args, str[i]);
			else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
				count += write_number(args, str[i]);
			else if (str[i] == 'x' || str[i] == 'X')
				count += write_hexa(args, str[i]);
			else if (str[i] == 'p')
				count += write_pointer(args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}


/* int	main(void)
{	//char  c = 'W';
	//void *s = "jdfkf";
	int num = ft_printf("ft_printf : hello %x %X  it's Nelly\n", 423,423);
	printf("length is : %d", num);
	printf("\nprintf : hello %x %X it's Nelly\n", 423,423);
	return (0);
} */
