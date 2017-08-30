/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_search_field.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:50:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:50:43 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_index	ft_var_field(char *flag, char **clean_flag, t_index index, \
va_list *ap)
{
	int		arg;

	arg = 0;
	if (ft_isdigit(flag[index.i + 1]))
	{
		arg = va_arg(*ap, int);
		index.i++;
		return (ft_printf_search_field(flag, clean_flag, index, ap));
	}
	if ((arg = va_arg(*ap, int)) < 0 && (*clean_flag)[index.j - 1] != '-')
		*clean_flag = ft_strjoin_free(&(**clean_flag), ft_itoa(arg), 3);
	else if (arg < 0)
		*clean_flag = ft_strjoin_free(&(**clean_flag), ft_itoa((-arg)), 3);
	else
		*clean_flag = ft_strjoin_free(&(**clean_flag), ft_itoa(arg), 3);
	index.i++;
	return (index);
}

t_index			ft_printf_search_field(char *flag, char **clean_flag, \
t_index index, va_list *ap)
{
	if (flag[index.i] == '*')
		index = ft_var_field(flag, clean_flag, index, ap);
	else if (ft_isdigit(flag[index.i]))
	{
		while (ft_isdigit(flag[index.i]))
			index.i++;
		if (flag[index.i] == '*')
			return (ft_printf_search_field(flag, clean_flag, index, ap));
		*clean_flag = ft_strjoin_free(*clean_flag, \
		ft_itoa(ft_printf_get_field(flag)), 3);
	}
	return (index);
}
