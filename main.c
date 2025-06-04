/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:34:54 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/04 16:41:01 by mayahiao         ###   ########.fr       */
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
		}
		ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}

int	main(void)
{	char  c = 'W';
	char  *s = "THERE";
	ft_printf("ft_printf : hello %% %c %% %s it's Nelly\n", c,s);
	printf("\nprintf : hello %% %c %% %s it's Nelly\n", c,s);
	return (0);
}
