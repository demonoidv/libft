#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0 && (n = -n) && n > -2147483648)
		ft_putchar('-');
	if ((n / 10) > 0)
		ft_putnbr(n / 10);
	(n == -2147483648) ? ft_putstr("-2147483648") : ft_putchar(n % 10 + 48);
}
