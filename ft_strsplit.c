/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:18:18 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/15 14:18:21 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	return (i);
}

static char	*ft_strdup_word(char const *str, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (!(word = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = str[i];
	word[i] = 0;
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = ft_count_words(s, c);
	if (!(result = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	j = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			result[++j] = ft_strdup_word(s, c);
		while (*s && *s != c)
			s++;
	}
	result[i] = NULL;
	return (result);
}
