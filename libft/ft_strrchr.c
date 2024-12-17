#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t i;
    char *p;
    
    i = 0;
    p = NULL;
    while (*(s + i) != '\0')
    {
        if (*(s + i) == (char)c)
            p = (char *)s + i;
        i++;
    }
    if (c == '\0')
        return((char *)s + i);  
    if (p)
        return(p);
               
    return(NULL);
}