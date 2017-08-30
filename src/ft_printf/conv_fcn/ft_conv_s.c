/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:51 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:04:46 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_s(char *flag, va_list *ap, t_att attribute)
{
	int			i;
	char		*res;
	const char	*input;

	i = ft_strlen(flag) - 1;
	input = NULL;
	if (flag[i] != 's' || (flag[i] == 's' && flag[i - 1] == 'l'))
		return (NULL);
	input = va_arg(*ap, char *);
	if (!input && (attribute.prec > 0 || (!attribute.field && \
	attribute.prec == -1) || attribute.field))
		input = "(null)";
	else if (!input)
		input = "\0";
	res = ft_strdup(input);
	if (attribute.prec != -1)
		res = ft_printf_prec_s(res, attribute.prec);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, \
		(ft_printf_attribute_zero(attribute)));
	return (res);
}
