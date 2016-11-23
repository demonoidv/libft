#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;

	if (s && f)
	{
		i = 0;
		while (s[i])
			f(&s[i++]);
	}
}
