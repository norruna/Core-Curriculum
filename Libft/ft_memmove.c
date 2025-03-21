#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    if (!dest && !src)
        return (NULL);
    
    dst = (unsigned char *)dest;
    src = (const unsigned char *)src;
    
    if (dst > src && dst < src+ n)
    {
        // Copy backwards to prevent overlap issues
        dst += n;
        src += n;
        while (n--)
            *(--dst) = *(--src);
    }
    else
    {
        // Copy forwards
        while (n--)
            *dst++ = *src++;
    }
    
    return dest;
}

