#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char *str = (char *) s;
	i = 0;
	if (!c)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		++i;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int	main(void)
{
const char *str = "hello thzre";
	char c = 'z';

//        printf("Test case %d:\n", i + 1);
        printf("str: \"%s\", to_find: \"%c\"\n", str, c);
        printf("ft_strrchr : %s\n", ft_strrchr(str, c));
        printf("strrchr : %s\n", strrchr(str, c));
        printf("\n");


    return 0;
}
