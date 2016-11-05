#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	tmp_c;

	tmp = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	while(n)
	{
		if(tmp_c == *tmp)
			return(tmp);
		tmp++;
		n--;
	}
	return(NULL);
}
