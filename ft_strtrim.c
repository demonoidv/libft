/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:18:35 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:18:37 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i[3];
	int		len;

	i[0] = -1;
	len = (ft_strlen(s) - 1);
	while (s[len] != ' ' && s[len] != '\n' && s[len] != '\t')
		len--;
	i[2] = len;
	while (s[i[0]++] != ' ' && s[i[0]] != '\n' && s[i[0]] != '\t')
	{
		len--;
	}
	i[1] = (i[0] - 1);
	i[0] = -1;
	if ((str = ft_strnew((len + 1))))
	{
		str[(len + 1)] = '\0';
		while (i[1] <= i[2])
		{
			str[(i[0]++)] = s[(i[1]++)];
		}
	}
	return (str);
}
