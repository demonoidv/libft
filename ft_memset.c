#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while(n)
	{
		*tmp = c;
		tmp++;
		n--;
	}
	return(s);
}
