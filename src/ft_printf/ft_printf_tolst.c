/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tolst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:16:19 by vsporer           #+#    #+#             */
/*   Updated: 2017/07/20 15:00:03 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_printf_skip_nullchar(char *str, int nullchar)
{
	int		i;

	i = 0;
	while (str[i] || nullchar)
	{
		if (str[i] == '\0' && nullchar)
			nullchar--;
		i++;
	}
	return (i);
}

static void	ft_lstadd_arg(t_list **print_list, t_att attribute)
{
	size_t	len;

	len = ft_printf_skip_nullchar(attribute.arg, attribute.nullchar);
	ft_lstaddback(print_list, ft_lstnew(attribute.arg, len));
	ft_strdel(&attribute.arg);
}

static int	ft_lstadd_format(t_list **print_list, char *format)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (format[len] == '%')
		return (1);
	while (format[len] && format[len] != '%')
		len++;
	tmp = ft_strsub(format, 0, len);
	ft_lstaddback(print_list, ft_lstnew(tmp, len));
	ft_strdel(&tmp);
	return ((int)len);
}

t_list		*ft_printf_tolst(char *format, int *nullchar, va_list *ap)
{
	t_list	*todel;
	t_list	*flag_list;
	t_list	*print_list;

	print_list = NULL;
	if (nullchar == 0)
		nullchar = 0;
	flag_list = ft_get_flag(format);
	while (*format)
	{
		if (*format == '%' && flag_list)
		{
			ft_lstadd_arg(&print_list, \
			ft_printf_switch(flag_list->content, ap));
			format += ft_strlen(flag_list->content);
			todel = flag_list;
			flag_list = flag_list->next;
			ft_memdel(&todel->content);
			free(todel);
		}
		else
			format += ft_lstadd_format(&print_list, format);
	}
	return (print_list);
}
