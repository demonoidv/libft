/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_lc_cup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:04:06 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:04:09 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_lc_cup(char *flag, va_list *ap, t_att *attribute)
{
	int			i;
	char		*res;
	wint_t		input;
	int			size;

	i = ft_strlen(flag) - 1;
	input = 0;
	res = NULL;
	if (!(flag[i] == 'C' || (flag[i] == 'c' && flag[i - 1] == 'l' && \
	flag[i - 2] != 'l')))
		return (NULL);
	input = va_arg(*ap, wint_t);
	size = ft_wcrtomb(res, (wchar_t)input);
	if (size > MB_CUR_MAX)
		return (NULL);
	res = ft_strnew(size + 1);
	size = ft_wcrtomb(res, (wchar_t)input);
	res[size] = '\0';
	if (!res[0])
		attribute->nullchar++;
	return (ft_printf_field(flag, (char *)res, *attribute, \
	ft_printf_attribute_zero_char(*attribute)));
}
