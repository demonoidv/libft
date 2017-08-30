/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:59:58 by vsporer           #+#    #+#             */
/*   Updated: 2017/07/20 11:10:44 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_get_prec(char *flag)
{
	if ((flag = ft_strchr(flag, '.')))
		return (ft_atoi(flag + 1));
	else
		return (-1);
}

char	*ft_printf_prec(char *flag, char *res, int prec_value)
{
	char	*tmp;
	int		i;
	int		posconv;

	posconv = ft_strlen(flag) - 1;
	i = ((ft_strchr(flag, '+') && (flag[posconv] == 'd' || flag\
	[posconv] == 'i'))) ? (ft_strlen(res)) : (ft_strlen(res));
	if (i <= prec_value)
	{
		i = prec_value - i;
		if (*res == '-')
			i++;
		if (flag[posconv] == 'p')
			i += 2;
		if (!(tmp = ft_strnew(i)))
			return (NULL);
		while (i > 0)
			tmp[--i] = '0';
		res = (ft_strjoin_free(tmp, res, 3));
	}
	return (res);
}

char	*ft_printf_prec_s(char *res, int prec_value)
{
	char	*ret;

	if ((int)ft_strlen(res) > prec_value && prec_value >= 0)
	{
		ret = ft_strnew((size_t)prec_value);
		ret = ft_strncpy(ret, res, prec_value);
		ft_strdel(&res);
		return (ret);
	}
	return (res);
}
