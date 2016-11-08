#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	
	i = 0;
	len = (start + len);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (start < i)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
