/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_attribute_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:38:08 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:38:09 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_printf_attribute_zero(t_att attribute)
{
	if (attribute.zero && !attribute.minus && attribute.prec <= 0)
		return ('0');
	return (' ');
}

char	ft_printf_attribute_zero_char(t_att attribute)
{
	if (attribute.zero && !attribute.minus)
		return ('0');
	return (' ');
}

char	ft_printf_attribute_zero_num(t_att attribute)
{
	if (attribute.zero && !attribute.minus && attribute.prec < 0)
		return ('0');
	return (' ');
}
