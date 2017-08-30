/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ls_sup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:04:15 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:05:36 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_ls_sup_wcsrtombs(char *res, const wchar_t *input, \
t_att attribute)
{
	int			i;
	size_t		size;

	i = 0;
	size = 0;
	if (!(size = ft_wcsrtombs(res, (wchar_t *)input, attribute.prec)))
		return (ft_strdup("\0"));
	if (attribute.prec >= 0 && (size - attribute.prec) > 0)
		i = attribute.prec;
	else
		i = size;
	res = ft_strnew(i + 1);
	size = ft_wcsrtombs(res, (wchar_t *)input, i);
	return (res);
}

char	*ft_conv_ls_sup(char *flag, va_list *ap, t_att attribute)
{
	int				i;
	char			*res;
	const wchar_t	*input;

	i = ft_strlen(flag) - 1;
	res = NULL;
	if (!(flag[i] == 'S' || (flag[i] == 's' && flag[i - 1] == 'l' && \
	flag[i - 2] != 'l')))
		return (NULL);
	input = va_arg(*ap, wchar_t *);
	if (!input && (attribute.prec > 0 || (!attribute.field && \
	attribute.prec == -1) || attribute.field))
		res = ft_strdup("(null)");
	else if (!input || (input && input[0] == '\0'))
		res = ft_strdup("\0");
	else if (input[0] == '\0' && attribute.space)
		return (ft_strdup(" "));
	else
		res = ft_conv_ls_sup_wcsrtombs(res, input, attribute);
	if (attribute.field)
		res = ft_printf_field(flag, res, attribute, \
		ft_printf_attribute_zero(attribute));
	return (res);
}
