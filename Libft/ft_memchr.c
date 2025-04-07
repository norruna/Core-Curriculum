#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *big;
	size_t	i;

	big = (unsigned char *)s;
	i = 0;
	if (!c)
		return (big);
	while (big[i] != '\0' && i < n)
	{
		if (c == big[i])
			return (&big[i]);
	
		++i;
	}
	return (0);
}
