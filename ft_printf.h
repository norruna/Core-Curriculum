/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:12 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/06 18:34:59 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		write_string(va_list args, int c);
int		write_number(va_list args, int c);
int		write_hexa(va_list args, int c);
int		write_pointer(va_list args);
int		format_specifier(va_list args, int c);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_putnbr(int n, int *count);
void	hexa_tab(void);

#endif
