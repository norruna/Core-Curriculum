#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *big;
	unsigned char little;
	size_t	i;
	if (!s)
		return (0);
	big = (unsigned char *)s;
	little = (unsigned char) c;
	i = 0;
	
	while (i < n)
	{
		if (little == big[i])
			return ((void *)&big[i]);
		i++;
	}
	return (0);
}

