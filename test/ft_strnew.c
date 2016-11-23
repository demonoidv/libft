#include "libft.h"

char	*ft_strnew(unsigned long size)
{
	char *str;

	if ((str = (char*)ft_memalloc(size + 1)))
	{
		str[size] = 0;
		return (str);
	}
	return (NULL);
}
