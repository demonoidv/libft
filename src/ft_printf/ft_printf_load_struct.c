/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_load_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:49:31 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/30 22:08:40 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_att	ft_printf_load_struct(char *flag, va_list *ap)
{
	t_att	att;

	att = ft_printf_clear_flag(flag, ap);
	if (!att.flag_ok)
		return (att);
	att.field = ft_printf_get_field(att.clean_flag);
	att.prec = ft_printf_get_prec(att.clean_flag);
	att.sharp = (ft_strchr(att.clean_flag, '#')) ? (1) : (0);
	att.zero = ft_printf_get_zero(att.clean_flag);
	att.minus = ft_printf_get_minus(att.clean_flag);
	att.space = (ft_strchr(att.clean_flag, ' ')) ? (1) : (0);
	att.sign = (ft_strchr(att.clean_flag, '+')) ? (1) : (0);
	if (att.flag_ok == -1)
		return (att);
	ft_strdel(&att.clean_flag);
	return (att);
}
