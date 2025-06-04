#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h> //for printf testing to be deleted before pushing
#include <unistd.h>
#include <string.h>
#include <stdarg.h> //contains va_list a type to be able to work with va_args copy start and end
#include "libft/libft.h"

int ft_printf(const char *, ...);
int write_string(va_list args,int c, int i);
int	write_number(va_list args, int c, int i);
int	write_hexa(va_list args, int c, int i);
void	ft_putnbr_unsigned_fd(int n, int fd);
void hexa_tab(void);
#endif
