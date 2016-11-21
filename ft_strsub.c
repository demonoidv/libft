/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:11:49 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/17 16:11:52 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if ((dest = ft_strnew((len))) && s)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = 0;
		return (dest);
	}
	return (NULL);
}
