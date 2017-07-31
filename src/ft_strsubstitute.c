#include "libft.h"

char	*ft_strsubstitute_minlen(char *s1, char *chr, char *s2, size_t len)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = ft_strstr_minlen(s1, chr, len);
	if (ret != NULL)
	{
		i = ret - s1;
		if (!(tmp = ft_strnew(ft_strlen(s1 + ft_strlen(chr) + i + 1))))
			return (NULL);
//		*tmp = ' ';
		ft_strcpy((tmp), (s1 + ft_strlen(chr) + i));
		ret = ft_strjoin_free(ft_strsub(s1, 0, i), \
		ft_strjoin_free(s2, tmp, 2), 3);
//		ret[i] = '\0';
	}
	return (ret);
}

char	*ft_strsubstitute(char *s1, char *chr, char *s2, size_t len)
{
	char	*ret;
	int		i;

	if (len)
		return (ft_strsubstitute_minlen(s1, chr, s2, len));
	ret = ft_strstr(s1, chr);
	if (ret != NULL)
	{
		i = ret - s1;
		ret = ft_strjoin_free(ft_strsub(s1, 0, i), \
		ft_strjoin(s2, (s1 + ft_strlen(chr) + i)), 3);
	}
	return (ret);
}
