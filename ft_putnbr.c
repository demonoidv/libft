#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		nb = nb / 10;
		ft_putnbr(nb);
		ft_putchar('8');
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}
