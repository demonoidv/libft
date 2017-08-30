/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xp_xup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:05:06 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_firstchar_zero(char *res, int *i, t_att *attribute)
{
	if (*res == '0')
	{
		attribute->sharp = 0;
		attribute->sign = 0;
	}
	if (attribute->prec == 0 && *res == '0')
		*i = 0;
}

char		*ft_conv_xp_xup(char *flag, va_list *ap, t_att attribute)
{
	int		i;
	char	*res;

	i = ft_strlen(flag) - 1;
	if (flag[i] != 'x' && flag[i] != 'X')
		return (NULL);
	if (!(res = ft_printf_lenmod_ui(flag, ap, i, 16)))
		return (NULL);
	ft_firstchar_zero(res, &i, &attribute);
	if (attribute.prec > -1)
		res = ft_printf_prec(flag, res, attribute.prec);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, \
		ft_printf_attribute_zero_num(attribute));
	if (attribute.sharp)
		res = ft_printf_attribute_sharp(flag, res, 'x', attribute);
	if (i == 0)
		res[(ft_strlen(res) - 1)] = ((ft_strlen(res) - 1) == 0) ? '\0' : ' ';
	i = -1;
	while (res[++i] && flag[ft_strlen(flag) - 1] == 'X')
		res[i] = ft_toupper(res[i]);
	return (res);
}
