/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_not_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:42:02 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:42:03 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_not_valid(char *flag, t_att attribute)
{
	char	c;
	char	*res;

	c = flag[ft_strlen(flag) - 1];
	if ((res = ft_strnew(1)))
		res[0] = c;
	return (ft_printf_field(flag, (char *)res, attribute, \
	ft_printf_attribute_zero(attribute)));
}
