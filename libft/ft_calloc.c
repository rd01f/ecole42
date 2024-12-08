#include "libft.h"

void *ft_calloc(size_t num, size_t size)
{
    void *mem;

    if (num == 0 || size == 0)
        num = size = 1;
    if((int)num < 0 || (int)size < 0)
         return (NULL);
    mem = malloc(num * size);
    if(!mem)
        return(NULL);
    ft_bzero(mem, num * size);
    return(mem);
}
