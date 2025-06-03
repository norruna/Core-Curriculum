#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_list copy;
	va_start(args, str);
	int	i = 0;
	const char	*s = str;
	//va_copy(copy,args);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{	
			if (s[i + 1] == 's')
			{	

				ft_putstr_fd(va_arg(args,char *),1);
				i = i + ft_strlen(;
				break;
			}
			else if (s[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				i = i + 2;
			}
		}
		ft_putchar_fd(s[i], 1);
		//printf("%c",s[i]);
		i++;	
	
	}
	va_end(args);
	return (i); //number of char printed
}

int	main(void)
{	char  *c = "there\n";
	int num = ft_printf("hello %%wor%s ld\n", c);
	return (0);
}
