#include "libft.h"

int		ft_atoi(char *str)
{
	int i;
	int r;
	int neg;

	i = 0;
	r = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10;
		r = ((str[i] - 48) + r);
		i++;
	}
	return (r * neg);
}
