#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;
	size_t	i;

	i = 0;
	if((tmp = (void*)malloc(sizeof(*tmp) * n)))
	{
		while(i < n)
		{
			((char*)tmp)[i] = ((char*)src)[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			((char*)dest)[i] = ((char*)tmp)[i];
			i++;
		}
		free(tmp);
	}
	return(dest);
}
