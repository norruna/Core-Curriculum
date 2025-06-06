/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:12 by mayahiao          #+#    #+#             */
/*   Updated: 2025/06/06 17:23:49 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> //for printf testing to be deleted before pushing
# include <unistd.h>
# include <string.h>
# include <stdarg.h> //va_list for va_args copy start and end
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int	    write_string(va_list args, int c);
int	    write_number(va_list args, int c);
int	    write_hexa(va_list args, int c);
int		write_pointer(va_list args);
void	ft_putnbr_unsigned_fd(unsigned int n, int *count);
void	ft_putnbr_ft(int n, int *count);
void	hexa_tab(void);

#endif
