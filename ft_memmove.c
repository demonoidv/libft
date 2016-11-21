/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:14:35 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:41:36 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;
	size_t	i;

	i = 0;
	if ((tmp = (void*)malloc(sizeof(*tmp) * n)))
	{
		while (i < n)
		{
			((char*)tmp)[i] = ((char*)src)[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			((char*)dest)[i] = ((char*)tmp)[i];
			i++;
		}
		ft_memdel(tmp);
	}
	return (dest);
}
