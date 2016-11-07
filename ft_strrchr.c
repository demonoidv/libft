/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:55:37 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/07 12:07:39 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp;

	i = ft_strlen(s);
	tmp = (char)c;
	s = s + i;
	while (i >= 0)
	{
		if (*s == tmp)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
