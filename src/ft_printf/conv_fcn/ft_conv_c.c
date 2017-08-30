/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:34 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:03:43 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_c(char *flag, va_list *ap, t_att *attribute)
{
	int				i;
	unsigned char	*res;
	unsigned char	input;

	i = ft_strlen(flag) - 1;
	input = 0;
	if (flag[i] != 'c' || (flag[i] == 'c' && flag[i - 1] == 'l' && \
	flag[i - 2] != 'l'))
		return (NULL);
	input = (unsigned char)va_arg(*ap, int);
	if ((res = (unsigned char *)ft_strnew(1)))
		if (!(res[0] = input))
			attribute->nullchar++;
	return (ft_printf_field(flag, (char *)res, *attribute, \
	(ft_printf_attribute_zero_char(*attribute))));
}
