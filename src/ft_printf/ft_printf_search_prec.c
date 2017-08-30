/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_search_prec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:49:35 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:49:37 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_index	ft_var_prec(t_index index, char **clean_flag, va_list *ap)
{
	int		arg;

	arg = 0;
	arg = va_arg(*ap, int);
	if (arg < 0)
	{
		index.i++;
		return (index);
	}
	else if (arg == 0)
		*clean_flag = ft_strjoin_free(*clean_flag, ".0", 1);
	else
		*clean_flag = ft_strjoin_free(*clean_flag, \
		ft_strjoin_free(".", ft_itoa(arg), 2), 3);
	index.i++;
	return (index);
}

t_index			ft_printf_search_prec(char *flag, char **clean_flag, \
t_index index, va_list *ap)
{
	if (flag[++index.i] == '*')
		index = ft_var_prec(index, clean_flag, ap);
	else if (!ft_isdigit(flag[index.i]))
	{
		while (ft_isdigit(flag[index.i]))
			index.i++;
		*clean_flag = ft_strjoin_free(*clean_flag, \
		ft_strjoin_free(".", ft_itoa(ft_printf_get_prec(flag)), 2), 3);
	}
	else
		*clean_flag = ft_strjoin_free(*clean_flag, ".0", 1);
	return (index);
}
