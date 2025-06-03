#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	int	i = 0;
	char	b;
	while (str[i] != '\0')
	{
		b = va_arg(str[i],int);
		ft_putchar_fd(1, str[i]);
	 	i++;
	
	}
	va_end(args);
	return (i); //number of char printed
}

int	main(void)
{	int c;
	int num = ft_printf("hello there\n", c);
	return (0);
}
