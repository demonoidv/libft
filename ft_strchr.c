#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tmp;

	tmp = (char) c;
	while (*s)
	{
		if (*s == tmp)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
