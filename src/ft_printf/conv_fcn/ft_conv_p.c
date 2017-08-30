/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:44:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:44:41 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_len_zero(char *res, t_att attribute)
{
	res[ft_strlen(res) - 1] = '\0';
	if ((attribute.field - ft_strlen(res)) > 0)
		res = ft_strjoin_free(" ", res, 2);
	return (res);
}

char		*ft_conv_p(char *flag, va_list *ap, t_att attribute)
{
	int		i;
	int		posconv;
	char	*res;

	i = 1;
	posconv = ft_strlen(flag) - 1;
	if (flag[posconv] != 'p')
		return (NULL);
	if (!(res = ft_printf_lenmod_ui(flag, ap, posconv, 16)))
		return (NULL);
	if (attribute.prec == 0 && res[0] == '0')
		i = 0;
	if (attribute.prec > -1)
		res = ft_printf_prec(flag, res, attribute.prec);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, \
		ft_printf_attribute_zero(attribute));
	res = ft_printf_attribute_sharp(flag, res, 'x', attribute);
	if (i == 0)
		res = ft_len_zero(res, attribute);
	if (res[0] == '\0' || (res[0] == '0' && res[1] == '\0'))
		return (ft_strjoin_free("0x", res, 2));
	return (res);
}
