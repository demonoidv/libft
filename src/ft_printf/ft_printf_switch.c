/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_switch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:00:05 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/30 22:08:03 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_att	ft_printf_switch_spec(char *flag, t_att attribute, va_list *ap)
{
	if ((attribute.arg = ft_conv_lc_cup(flag, ap, &attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_ls_sup(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_b(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_percent(flag, attribute)))
		return (attribute);
	else if (attribute.flag_ok == 1)
	{
		attribute.arg = ft_conv_not_valid(flag, attribute);
		return (attribute);
	}
	else
		return (attribute);
}

t_att	ft_printf_switch(char *flag, va_list *ap)
{
	t_att	attribute;

	attribute = ft_printf_load_struct(flag, ap);
	if (!attribute.flag_ok)
		return (attribute);
	if ((attribute.arg = ft_conv_c(flag, ap, &attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_di(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_o(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_u(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_xp_xup(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_s(flag, ap, attribute)))
		return (attribute);
	else if ((attribute.arg = ft_conv_p(flag, ap, attribute)))
		return (attribute);
	else
		return (ft_printf_switch_spec(flag, attribute, ap));
}
