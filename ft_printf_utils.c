/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:52:07 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/04 16:03:53 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   write_string(va_list args, int c, int i)
{
    if (c == 's')
		ft_putstr_fd(va_arg(args,char *),1);
    else
        ft_putchar_fd(va_arg(args, int), 1);
    i = i + 2;
        return (i);
}