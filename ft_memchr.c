/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:14:12 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:37:39 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	tmp_c;

	tmp = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	while (n)
	{
		if (tmp_c == *tmp)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
