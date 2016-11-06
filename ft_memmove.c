#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*tmp_s;
	char	*tmp_d;
	char	*tmp;

	tmp_s = (char *)src;
	tmp_d = (char *)dest;
	if(tmp = (char *)malloc(sizeof(*tmp) * n))
	{
		while(n)
		{
			*tmp = *tmp_s;
			*tmp_d = *tmp;
			tmp++;
			tmp_s++;
			tmp_d++;
			n--;
		}
		free(tmp);
		return(dest);
	}
	return(NULL);
}
