#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char *str = (char *) s;
	char *tmp = str;
	i = 0;
	if (!c)
		return (str);
	tmp = ft_strchr(&str[i],c);
	while (tmp != 0)
	{
		tmp = ft_strchr(tmp,c) + 1;
		if (ft_strchr(tmp,c))
		{
			tmp = ft_strchr(tmp,c);
		}
		else
			return (tmp - 1);
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
const char *str = "hzllo thezefksldfssl;fsnewzhere";
	char c = 'z';

//        printf("Test case %d:\n", i + 1);
        printf("str: \"%s\", to_find: \"%c\"\n", str, c);
        printf("ft_strrchr : %s\n", ft_strrchr(str, c));
        printf("strrchr : %s\n", strrchr(str, c));
        printf("\n");


    return 0;
}*/
