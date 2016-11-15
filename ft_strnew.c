/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:17:50 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 15:35:15 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	str[size - 1] = '\0';
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
