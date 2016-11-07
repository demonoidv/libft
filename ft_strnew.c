/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:03:24 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/07 14:10:51 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char *)ft_memalloc(size);
	i = 0;
	str[size - 1] = '\0';
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
