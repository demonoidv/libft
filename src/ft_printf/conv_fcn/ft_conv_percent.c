/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:42:51 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:42:59 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_percent(char *flag, t_att attribute)
{
	int		i;
	char	*res;

	i = ft_strlen(flag) - 1;
	res = NULL;
	if (i == 0 || flag[i] != '%')
		return (NULL);
	if (!(res = ft_strdup("%")))
		return (NULL);
	return (ft_printf_field(flag, res, attribute, \
	(ft_printf_attribute_zero_char(attribute))));
}
