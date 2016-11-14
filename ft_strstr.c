/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:09:34 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/07 12:27:51 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (haystack[i])
	{
		while (haystack[i + c] == needle[c] && needle[c])
			c++;
		if (!(needle[c]))
			return (&((char*)haystack)[i]);
		c = 0;
		i++;
	}
	if (haystack[i] == needle[c])
		return (&((char*)haystack)[i]);
	return (NULL);
}
