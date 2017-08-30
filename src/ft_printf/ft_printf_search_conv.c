/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_search_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:45:41 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:00:18 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_search_conv(char *flag, int i)
{
	char	*conv;
	int		j;

	j = 0;
	if (!(conv = ft_strdup("%sSpdiouxXcCDOUaAbBeEfFgGHIJkKLmMnNPqQrRtTvVwWyYZ")\
))
		return (0);
	if (ft_islenmod(flag[i]))
		i++;
	if ((flag[i] == 'h' && flag[i - 1] == 'h') || (flag[i] == 'l' && \
	flag[i - 1] == 'l'))
		i++;
	while (conv[j] && conv[j] != flag[i])
		j++;
	if (conv[j])
		i++;
	ft_strdel(&conv);
	if (flag[i])
		return (i);
	else
		return (0);
}
