#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
   size_t len_fstr;
   size_t len_sestr;
   size_t i;
   char *newstr;

   i = 0;
   len_fstr = ft_strlen(s1);
   len_sestr = ft_strlen(s2);
   newstr = malloc(len_fstr + len_sestr + 1);
   while(i < len_fstr)
   {
      *(newstr + i) = *(s1 + i);
      i++;
   }
   i = 0;
   while(i < len_sestr)
   {
      *(newstr + i + len_fstr) = *(s2 + i);
      i++;
   }
   *(newstr + i + len_fstr) = '\0';
   return (newstr);
}