/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_clear_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:50:45 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/30 22:38:07 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_index	ft_printf_get_attribute(char *flag, char *clean_flag, \
t_index index)
{
	char	*tmp;
	char	*newflag;

	newflag = ft_strdup(flag);
	flag[ft_strlen(newflag)] = '\0';
	index.j = 1;
	clean_flag[0] = '%';
	while (ft_isattribute((flag)[index.i]))
		(index.i)++;
	if (index.i != 1 && (tmp = ft_strsub(newflag, 1, (index.i - 1))))
	{
		if (ft_strchr(tmp, '#'))
			clean_flag[index.j++] = '#';
		if (ft_strchr(tmp, '+'))
			clean_flag[index.j++] = '+';
		else if (ft_strchr(tmp, ' '))
			clean_flag[index.j++] = ' ';
		if (ft_strchr(tmp, '-'))
			clean_flag[index.j++] = '-';
		else if (ft_strchr(tmp, '0'))
			clean_flag[index.j++] = '0';
		ft_strdel(&tmp);
	}
	ft_strdel(&newflag);
	return (index);
}

static t_att	ft_switch_clear_flag(char *flag, t_att att, t_index index, \
va_list *ap)
{
	index = ft_printf_get_attribute(flag, att.clean_flag, index);
	index = ft_printf_search_field(flag, &att.clean_flag, index, ap);
	if (flag[index.i] == '.')
		index = ft_printf_search_prec(flag, &att.clean_flag, index, ap);
	if (!(index.i = ft_printf_search_conv(flag, index.i)) && flag[1])
	{
		att.clean_flag = ft_strjoin_free(att.clean_flag, \
		flag + (ft_strlen(flag) - 1), 1);
		att.flag_ok = 1;
	}
	else
	{
		att.clean_flag = ft_strjoin_free(att.clean_flag, (flag + index.i), 1);
		if (ft_isalpha(att.clean_flag[ft_strlen(att.clean_flag) - 1]))
			att.flag_ok = -1;
	}
	return (att);
}

t_att			ft_printf_clear_flag(char *flag, va_list *ap)
{
	t_index	index;
	t_att	att;

	index.i = 1;
	att = ft_printf_start_struct(flag);
	if (flag[ft_strlen(flag) - 1] == '%')
	{
		ft_strdel(&att.clean_flag);
		att.clean_flag = ft_strdup(flag);
		att.flag_ok = ((ft_strlen(flag) - 1) == 0) ? -1 : 1;
		return (att);
	}
	if (!att.clean_flag)
		return (att);
	return (ft_switch_clear_flag(flag, att, index, ap));
}
