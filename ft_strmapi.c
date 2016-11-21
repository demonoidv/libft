/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:09:58 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/17 16:10:01 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	if (s && f)
	{
		if ((dest = ft_strnew(ft_strlen(s))))
		{
			i = 0;
			while (s[i])
			{
				dest[i] = f(i, s[i]);
				i++;
			}
		}
		return (dest);
	}
	return (NULL);
}
