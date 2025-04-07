#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	unsigned int	i;

	str = (char *)s;
	char	*result = (char *) malloc ((ft_strlen(str) + 1 )* sizeof(char));
	i = 0;
	while (str[i])
	{
	
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

char upper(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = 32;
	return (c);
}

int	main(void)
{
	char *res;

	res = ft_strmapi("0123456789",upper);
	printf("the resulting string is : %s\n",res);
	free(res);
	return (0);
}

