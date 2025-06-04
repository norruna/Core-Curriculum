/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:34:54 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/04 18:21:21 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	const char	*s;

	s = str;
	i = 0;
	va_start(args, str);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 's' || s[i + 1] == 'c' || s[i + 1] == '%')
				i = write_string(args, s[i + 1], i);
			else if (s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u')
				i = write_number(args, s[i + 1], i);
			else if (s[i + 1] == 'p' || s[i + 1] == 'x'|| s[i + 1] == 'X')
				i = write_hexa(args, s[i + 1], i);
		}
		ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}

int	main(void)
{	//char  c = 'W';
	char  *s = malloc(1);
	ft_printf("ft_printf : hello %x %X %p it's Nelly\n", 42,42, s);
	printf("\nprintf : hello %x %X %p it's Nelly\n", 42,42, s);
	return (0);
}
