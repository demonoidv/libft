/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:58:49 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:27:33 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_tostr(char **ret, t_list *list)
{
	t_list	*todel;
	char	*tmp;
	int		size;
	int		i;

	todel = list;
	size = 1;
	i = 0;
	while (todel && (size += todel->content_size))
		todel = todel->next;
	*ret = ft_strnew((size_t)size);
	tmp = *ret;
	while (list && *ret)
	{
		todel = list;
		ft_memcpy(tmp, list->content, (list->content_size));
		tmp = ft_strchr(tmp, '\0');
		i += list->content_size;
		ft_memdel(&(list->content));
		list = list->next;
		free(todel);
	}
	return (i);
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	t_list	*list;
	int		i;
	int		nullchar;

	i = 0;
	nullchar = 0;
	va_start(ap, format);
	list = ft_printf_tolst((char*)format, &nullchar, &ap);
	va_end(ap);
	if (list)
		i = ft_printf_tostr(ret, list);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*list;
	t_list	*todel;
	int		i;
	int		nullchar;

	nullchar = 0;
	va_start(ap, format);
	list = ft_printf_tolst((char*)format, &nullchar, &ap);
	i = 0;
	va_end(ap);
	if (list)
	{
		while (list)
		{
			todel = list;
			ft_putstr_minlen(list->content, list->content_size);
			i += list->content_size;
			ft_memdel(&(list->content));
			list = list->next;
			free(todel);
		}
	}
	return (i);
}
