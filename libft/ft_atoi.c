#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int digit;
    int sign;
    
    i = 0;
    sign = 1;
    digit = 0;
    while(ft_isspace((int)*(nptr + i)) == 1)
        i++;
    if(*(nptr + i) == '-' || *(nptr + i) == '+')
    {
        if(*(nptr + i) == '-')
            sign = -1; 
        i++;
    }    
    while(ft_isdigit((int)*(nptr + i)) == 1)
    {
        digit = digit * 10 + ((int)*(nptr + i) - '0') ;
        i++;
    }
    return(digit * sign);
}
