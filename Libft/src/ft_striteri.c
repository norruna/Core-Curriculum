#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void upper(unsigned int i, char *c)
{
	while (c[i])
	{
		if (i % 2 == 0)
			c[i] = 32;
		i++;
	}
}

int	main(void)
{
	char s[]  = "0123456789";
	ft_striteri(s,upper);
	printf("the resulting string is : %s\n",s);
	return (0);
}*/

