/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/05/02 10:58:44 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_b(char *flag, va_list *ap, t_att attribute)
{
	int		i;
	char	*res;
	char	c;

	c = ft_printf_attribute_zero(attribute);
	i = ft_strlen(flag) - 1;
	attribute.sign = 0;
	if (flag[i] != 'b' && flag[i] != 'B')
		return (NULL);
	if (!(res = ft_printf_lenmod_ui(flag, ap, i, 2)))
		return (NULL);
	attribute.sign = 0;
	if (attribute.sharp)
		res = ft_strjoin_free("0b", res, 2);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, ' ');
	if (i == 0)
		res[(ft_strlen(res) - 1)] = ((ft_strlen(res) - 1) == 0) ? '\0' : ' ';
	return (res);
}
