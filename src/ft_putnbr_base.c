/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:47:01 by vsporer           #+#    #+#             */
/*   Updated: 2019/08/27 15:02:24 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long n, int base)
{
	if (base > 32 || base < 2)
		return ;
	if (n < 0 && (n = -n))
		ft_putchar('-');
	if ((n / base) > 0)
		ft_putnbr_base(n / base, base);
	if (n % base > 9)
		ft_putchar((n % base - 10) + 'A');
	else
		ft_putchar(n % base + '0');
}
