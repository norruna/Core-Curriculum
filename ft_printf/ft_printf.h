/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:12 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 00:26:36 by nellys-simu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include "../Libft/libft.h"

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
