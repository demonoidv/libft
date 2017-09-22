/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubstitute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:03:07 by vsporer           #+#    #+#             */
/*   Updated: 2017/09/18 12:03:09 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubstitute(char *s1, char *chr, char *s2)
{
	char	*ret;
	int		i;

	ret = ft_strstr(s1, chr);
	if (ret != NULL)
	{
		i = ret - s1;
		ret = ft_strjoin_free(ft_strsub(s1, 0, i), \
		ft_strjoin(s2, (s1 + ft_strlen(chr) + i)), 3);
	}
	return (ret);
}
