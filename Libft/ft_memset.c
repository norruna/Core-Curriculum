#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_char;
	size_t	i;

	i = 0;
	s_char	= s;
	while (i < n)
	{
		s_char[i] = c;
		i++;
	}

	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char buf[0xff];
	ft_memset(buf,0, 0xff);
	ft_memset(buf, 'A',20);
	ft_memset(buf + 20,'B',20);
	printf("%s\n",buf);
	return (0);
}*/
