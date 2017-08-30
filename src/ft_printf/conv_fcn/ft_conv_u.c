/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:04:54 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_u(char *flag, va_list *ap, t_att attribute)
{
	int		i;
	char	*res;
	char	c;

	c = ft_printf_attribute_zero(attribute);
	i = ft_strlen(flag) - 1;
	if (flag[i] != 'u' && flag[i] != 'U')
		return (NULL);
	if (!(res = ft_printf_lenmod_ui(flag, ap, i, 10)))
		return (NULL);
	if (attribute.prec > -1)
		res = ft_printf_prec(flag, res, attribute.prec);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, c);
	if (res[0] == '0' && res[1] == '\0' && attribute.prec == 0)
		res[0] = '\0';
	return (res);
}
