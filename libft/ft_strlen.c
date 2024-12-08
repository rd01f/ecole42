#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if(*s == '\0')
		return(len);
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
