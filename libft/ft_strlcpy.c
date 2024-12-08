#include "libft.h"

size_t ft_strlcpy(char *dst , const char *src , size_t size)
{
    if (!dst || !src || (size == 0))
        return (ft_strlen(src));
    size_t i = 0;
    while (i < size -1 && *(src + i) != '\0')
    {
        *(dst + i) = *(src + i);
        i++;
    }
    *(dst + i) = '\0';
    return (ft_strlen(src));
}