#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dst;
	const unsigned char *source;
	size_t	i;

	i = 0;
	dst = dest;
	source = src;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

