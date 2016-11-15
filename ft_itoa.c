/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:12:04 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:28:09 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_nb(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		ft_itoa_cat(char **str, int n)
{
	char	c;

	c = (n % 10) + 48;
	if (n / 10 > 0)
		ft_itoa_cat(str, n / 10);
	*str = ft_strncat(*str, &c, 1);
}

char			*ft_itoa(int n)
{
	char	*str;

	if ((str = ft_strnew(ft_len_nb(n))))
	{
		ft_bzero(str, ft_len_nb(n) + 1);
		if (str)
		{
			if (n < 0)
			{
				if (n == -2147483648)
				{
					ft_strcpy(str, "-2147483648");
					return (str);
				}
				n = -n;
				str = ft_strcat(str, "-");
			}
			ft_itoa_cat(&str, n);
		}
	}
	return (str);
}
