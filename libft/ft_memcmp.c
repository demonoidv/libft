#include "libft.h"

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if(n)
	{
		while(n && tmp1 == tmp2)
		{
			tmp1++;
			tmp2++;
			n--;
		}
		return(tmp1 - tmp2);
	}
	return(0);
}
