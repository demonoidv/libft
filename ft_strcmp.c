#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	r = (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (r);
}
