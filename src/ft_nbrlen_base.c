/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:06:00 by vsporer           #+#    #+#             */
/*   Updated: 2019/08/27 15:10:07 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_base(long long n, int base)
{
	if (base > 32 || base < 2)
		return (-1);
	if (n < 0 && (n = -n))
		ft_putchar('-');
	if ((n / base) > 0)
		return (ft_nbrlen_base(n / base, base) + 1);
	return (1);
}
