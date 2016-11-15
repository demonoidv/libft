/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:13:53 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:13:56 by vsporer          ###   ########.fr       */
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
