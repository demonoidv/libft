#include "libft.h"

size_t	ft_wcsrtombs(char *str, wchar_t *wcs, size_t lenmax)
{
	int		i;
	int		size;
	int		ret;
	size_t	res;

	i = 0;
	ret = 0;
	res = 0;
	if (!(size = ft_wcsrlen(wcs, lenmax)))
		return (0);
	if (!str)
		return (size);
	while (ret < size)
	{
		ret = ft_wcrtomb((str + ret), wcs[i]);
		res += ret;
		i++;
	}
	return (res);
}
