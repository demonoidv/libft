/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:04:38 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_o(char *flag, va_list *ap, t_att attribute)
{
	int		i;
	char	*res;
	char	c;

	c = ft_printf_attribute_zero(attribute);
	i = ft_strlen(flag) - 1;
	attribute.sign = 0;
	if (flag[i] != 'o' && flag[i] != 'O')
		return (NULL);
	if (!(res = ft_printf_lenmod_ui(flag, ap, i, 8)))
		return (NULL);
	if (attribute.prec == 0 && res[0] == '0')
		i = 0;
	if (attribute.sharp)
		res = ft_printf_attribute_sharp(flag, res, 'o', attribute);
	if (attribute.prec > -1)
		res = ft_printf_prec(flag, res, attribute.prec);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, c);
	if (i == 0)
		res[(ft_strlen(res) - 1)] = ((ft_strlen(res) - 1) == 0) ? '\0' : ' ';
	if (attribute.sharp && i == 0)
		res = ft_printf_attribute_sharp(flag, res, 'o', attribute);
	return (res);
}
