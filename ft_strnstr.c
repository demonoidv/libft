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
	int i;
	int c;

	i = 0;
	c = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i + 1] && i <= len)
	{
		i = i - c;
		c = 0;
		while (big[i + 1] != '\0' && big[i] != little[c])
			i++;
		while (big[i] == little[c] && little[c] != '\0')
		{
			c++;
			i++;
		}
		i++;
		if (little[c] == '\0')
			return ((char *)&(big[i - c - 1]));
		return (0);
	}
	return (0);
}
