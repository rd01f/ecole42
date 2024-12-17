#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    const char *src = (char*)s;

    i = 0;
    while(i < n)
    {
        if(*(src + i) == (char)c)
            return((char*)src + i);
        i++;
    }
    return(NULL);
}