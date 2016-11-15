/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:14:22 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:14:24 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	char	*tmp_d;
	char	*tmp_s;

	tmp_d = (char *)dest;
	tmp_s = (char *)src;
	while (n)
	{
		*tmp_d = *tmp_s;
		tmp_d++;
		tmp_s++;
		n--;
	}
	return (dest);
}
