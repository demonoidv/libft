#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if ((dest = ft_strnew((len))) && s)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = 0;
		return (dest);
	}
	return (NULL);
}
