#include "ft_printf.h"

int ft_printf(const char *, ...)
{


}

int	main(void)
{
	const char *str = "Join this % this one";
	const char *str2 = "(with)";
	char *c = ft_strchr(str, '%');
	printf ("c : %s \n\n", c);
	char *str3 = ft_strjoin(str2, c + 1);
	printf ("str3 : %s \n\n", str3);
	char *sub = ft_substr(str,0,ft_strlen(c));
	printf ("sub : %s \n\n", sub);
	char *result = ft_strjoin(sub,str3); 
	printf ("result : %s \n\n", result);
	
	return (0);
}
