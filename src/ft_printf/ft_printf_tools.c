/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:50:49 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:50:56 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_att	ft_printf_start_struct(char *flag)
{
	t_att	att;

	att.clean_flag = ft_strnew(ft_strlen(flag));
	att.flag_ok = 0;
	att.sharp = 0;
	att.zero = 0;
	att.minus = 0;
	att.space = 0;
	att.sign = 0;
	att.field = 0;
	att.prec = 0;
	att.nullchar = 0;
	return (att);
}

int		ft_isattribute(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == '0' || c == ' ')
		return (1);
	return (0);
}

int		ft_islenmod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}
