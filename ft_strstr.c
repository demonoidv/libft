#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i + 1] != '\0')
	{
		i = i - c;
		c = 0;
		while (str[i + 1] != '\0' && str[i] != to_find[c])
			i++;
		while (str[i] == to_find[c] && to_find[c] != '\0')
		{
			c++;
			i++;
		}
		i++;
		if (to_find[c] == '\0')
			return (&(str[i - c - 1]));
		return (0);
	}
	return (0);
}
