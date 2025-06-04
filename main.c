#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	int	i = 0;
	const char	*s = str;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{	
			if (s[i + 1] == 's' || s[i + 1] == 'c') //if %s
				i = write_string(args, s[i + 1], i);
			else if (s[i + 1] == '%') //if %%
			{
				ft_putchar_fd('%', 1);
				i = i + 2;
			}
			//else if (s[i + 1] == 'c') //if %c
			
		}
		ft_putchar_fd(s[i], 1);
		i++;	
	
	}
	va_end(args);
	return (i); //number of char printed
}

int	main(void)
{	char  c = 'W';
	ft_printf("ft_printf : hello %% %c %% it's Nelly\n", c);
	printf("\nprintf : hello %% %c %% it's Nelly\n", c);
	return (0);
}
