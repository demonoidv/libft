/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:59:42 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/29 20:23:34 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_search_percent(const char *format)
{
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	return (i);
}

static int		ft_search_conv(char c)
{
	int		i;
	char	*conv;

	conv = "sSpdDioOuUxXcCaAbBeEfFgGIJJkKLmMnNPqQrRtTvVwWyYZ%";
	i = 0;
	while (conv[i] && conv[i] != c)
		i++;
	if (conv[i])
		return (1);
	else
		return (0);
}

static t_list	*ft_lstadd_flag(t_list *flag_list, char *format, int end)
{
	char	*tmp;
	t_list	*save;

	tmp = ft_strsub(format, 0, (end + 1));
	ft_lstaddback(&flag_list, ft_lstnew(tmp, (end + 1)));
	save = flag_list;
	ft_strdel(&tmp);
	while (flag_list->next)
		flag_list = flag_list->next;
	tmp = (char *)flag_list->content;
	if (ft_search_conv(tmp[end]))
		tmp[end + 1] = '\0';
	return (save);
}

t_list			*ft_get_flag(const char *format)
{
	int		i;
	int		end;
	t_list	*flag_list;

	flag_list = NULL;
	while (*(format += ft_search_percent(format)))
	{
		end = *format == '%' ? 1 : 0;
		if (*format)
			i = 0;
		while (format[end] && !i)
		{
			i = ft_search_conv(format[end]);
			if (i)
				flag_list = ft_lstadd_flag(flag_list, (char *)format, end);
			end++;
		}
		format += end;
	}
	return (flag_list);
}
