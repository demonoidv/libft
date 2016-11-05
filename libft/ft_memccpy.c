#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;

	tmp_d = (char *)dest;
	tmp_s = (char *)src;
	while(n && *tmp_s != c)
	{
		*tmp_d = *tmp_s;
		tmp_d++;
		tmp_s++;
		n--;
	}
	return(dest);
}
