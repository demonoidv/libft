#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	if (s)
	{
		if ((dest = ft_strnew(ft_strlen(s))))
		{
			i = 0;
			while (s[i])
			{
				dest[i] = f(s[i]);
				i++;
			}
		}
		return (dest);
	}
	return (NULL);
}
