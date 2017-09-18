/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:58:49 by vsporer           #+#    #+#             */
/*   Updated: 2017/09/18 12:02:22 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char *format)
{
	int		i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	if (*format != '%')
		ft_putstr_minlen(format, i);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_ftplst	*list;
	va_list		ap;
	int			ret;
	int			i;

	ret = 0;
	i = 0;
	list = ft_get_flag(format);
	va_start(ap, format);
	ft_printf_tolst(list, &ap);
	va_end(ap);
	while (*format)
	{
		if (*(format += i) == '%' && list)
		{
			ft_putstr_minlen(list->arg, list->size);
			ret += list->size;
			format += ft_strlen(list->flag);
			ft_ftplstdel(&list);
		}
		else if (*format == '%')
			format++;
		ret += (i = print_format((char*)format));
	}
	return (ret);
}
