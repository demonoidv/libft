/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:43:40 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/07 13:57:58 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *zmem;

	if ((zmem = (unsigned char *)malloc(sizeof(unsigned char) * size)))
	{
		ft_bzero(zmem, size);
		return (zmem);
	}
	return (NULL);
}
