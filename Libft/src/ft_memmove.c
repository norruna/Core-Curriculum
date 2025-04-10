#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *dst;
    const unsigned char *src1;

    if (!dest && !src)
        return (NULL);
    
    dst = (unsigned char *)dest;
    src1 = (const unsigned char *)src;
    
    if (dst > src1 && dst < src1 + n)
    {
        // Copy backwards to prevent overlap issues
        dst += n;
        src1 += n;
        while (n--)
            *(--dst) = *(--src1);
    }
    else
    {
        // Copy forwards
        while (n--)
            *dst++ = *src1++;
    }
    
    return dest;
}

