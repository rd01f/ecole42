#include "libft.h"

char *ft_strdup(const char *str)
{
    char *dup;
    size_t len;
    int i;

    i = 0;
    if(!str)
        return(NULL);
    len = ft_strlen(str) + 1;
    dup =  malloc( len);
    if(!dup)
        return(NULL);
    while(*(str + i) != '\0')
    {
        *(dup + i) = *(str + i);
        i++;
    }
    *(dup + i) = '\0';
    return (dup);
}