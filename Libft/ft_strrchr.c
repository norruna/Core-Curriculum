#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s) - 1;
	str = (char *)s;
	while (str[i] != c && i > 0)
	{
		i--;
	}
	if (i <= 0 && str[i] != c)
		return (NULL);
	return (&str[i]);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
const char *str = "tripouille";
	char c = 't';

//        printf("Test case %d:\n", i + 1);
        printf("str: \"%s\", to_find: \"%c\"\n", str, c);
        printf("ft_strrchr : %s\n", ft_strrchr(str, c));
        printf("strrchr : %s\n", strrchr(str, c));
        printf("\n");


    return 0;
}*/
