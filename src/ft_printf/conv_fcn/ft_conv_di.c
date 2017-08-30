/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:58:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/30 22:07:45 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_apply_neg(char *res, char *tmp)
{
	if (*res == ' ')
	{
		*tmp = *(tmp - 1);
		tmp = res;
		while (*(tmp + 1) == ' ')
			tmp++;
		if (*tmp != '0' && *(tmp + 1) == '0')
			*(tmp + 1) = '-';
		else
			*tmp = '-';
	}
	else if (*res == '0')
	{
		*tmp = *(tmp - 1);
		tmp = res;
		*tmp = '-';
	}
}

static char	*ft_printf_is_neg(char *res, t_att attribute)
{
	char	*tmp;

	if (!(tmp = ft_strchr(res, '-')))
		return (res);
	if ((res - tmp) && ((attribute.zero && attribute.prec < 0) \
	|| attribute.prec >= attribute.field))
	{
		*tmp = *(tmp - 1);
		tmp = res;
		if ((int)ft_strlen(res) < attribute.prec && attribute.prec >= \
		attribute.field)
			return (ft_strjoin_free("-", res, 2));
		if ((int)ft_strlen(res) < attribute.field && attribute.field > \
		attribute.prec)
			return (ft_strjoin_free("-", res, 2));
		*res = '-';
	}
	else
		ft_apply_neg(res, tmp);
	return (res);
}

char		*ft_conv_di(char *flag, va_list *ap, t_att attribute)
{
	int		i;
	char	*res;
	char	c;

	c = ft_printf_attribute_zero_num(attribute);
	i = ft_strlen(flag) - 1;
	if (flag[i] != 'd' && flag[i] != 'i' && flag[i] != 'D')
		return (NULL);
	if (!(res = ft_printf_lenmod_i(flag, ap, i)))
		return (NULL);
	if (!res[0])
		attribute.nullchar++;
	if (ft_strlen(res) == 1 && *res == '0' && attribute.prec == 0)
		*res = '\0';
	if (attribute.prec > -1)
		res = ft_printf_prec(flag, res, attribute.prec);
	if (attribute.field)
		res = ft_printf_field_di(res, attribute, c);
	if (attribute.space && !attribute.sign)
		res = ft_printf_attribute_space(res);
	else if (attribute.sign)
		res = ft_printf_attribute_sign_di(res, attribute);
	res = ft_printf_is_neg(res, attribute);
	return (res);
}
