/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:52:07 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/04 16:42:18 by mayahiao         ###   ########.fr       */
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

int	write_number(va_list args, int c, int i)
{
	if (c == 'i' || c == 'd')
	{

	}
	else
	{

	}
	i = i + 2;
	return (i);
}