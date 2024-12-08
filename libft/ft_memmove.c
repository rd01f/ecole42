#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char tmp[n];

    i = 0; 
    while(i < n)
    {
        tmp[i] = *((char*)src + i);
        i++;
    }
    i = 0;
     while(i < n)
    {
        *((char*)dest + i) = tmp[i];
        i++;
    }
    return(dest);
}