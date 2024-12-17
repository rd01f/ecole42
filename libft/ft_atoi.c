#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int digit;
    int len_digit;
    int power;

    i = 0;
    digit = 0;
    power = 1;
    len_digit = 0;
    while(ft_isspace((int)*(nptr + i)) == 1)
        i++;
    if(*(nptr + i) == '-' || *(nptr + i) == '+')
        i++;
    while(ft_isdigit((int)*(nptr + i + len_digit)) == 1)
    {
        len_digit++;
        if(len_digit > 9)
            return(INT_MAX);
    }
    len_digit--;
    while(ft_isdigit((int)*(nptr + i + len_digit)) == 1)
    {
        digit += ((int)*(nptr + i + len_digit--) - '0') * power ;
        power *= 10;
    }
    return(digit);
}