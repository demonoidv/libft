#include "libft.h"

char	*ft_strdup(char const *s)
{
	size_t	len;
	char	*str;
	int		i;

	i = 0;
	len = ft_strlen(s);
	if((str = (char *)malloc((len + 1) * sizeof(*str))) == NULL)
		return(NULL);
	while(s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return(str)
}
