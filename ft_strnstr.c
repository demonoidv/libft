/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:16:36 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/07 13:28:31 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int i;
	unsigned int c;

	i = 0;
	c = 0;
	while (big[i + c] && i < len)
	{
		while (big[i + c] == little[c] && little[c] && (i + c) < len)
			c++;
		if (little[c] == 0)
			return (&((char*)big)[i]);
		c = 0;
		i++;
	}
	if (i >= len)
		return (NULL);
	if (big[i] == little[c])
		return (&((char*)big)[i]);
	return (NULL);
}
