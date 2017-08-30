/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_attribute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:43:19 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:54:23 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_printf_attribute_sign_di(char *res, t_att attribute)
{
	int		i;

	i = 0;
	if (res)
	{
		if (ft_strchr(res, '-'))
			return (res);
		else
		{
			while (res[i] == ' ')
				i++;
			if (i && res[i - 1] == ' ')
				res[i - 1] = '+';
			else if (res[i] == '0' && \
			(attribute.field - ft_strlen(res)) <= 0 && res[i + 1])
				res[i] = '+';
			else
				res = ft_strjoin_free("+", res, 2);
			return (res);
		}
	}
	return (res);
}

char		*ft_printf_attribute_sign(char *res, t_att attribute)
{
	int		i;

	i = 0;
	if (res)
	{
		if (ft_strchr(res, '-'))
			return (res);
		else
		{
			while (res[i] == ' ')
				i++;
			if (i && res[i - 1] == ' ')
				res[i - 1] = '+';
			else if (res[i] == '0' && \
			(attribute.field - attribute.prec) > 0 && res[i + 1])
				res[i] = '+';
			else
				res = ft_strjoin_free("+", res, 2);
			return (res);
		}
	}
	return (res);
}

static char	*ft_apply_sharp(char *flag, char *res, int i, t_att attribute)
{
	if (!i)
	{
		if (res[0] == '0' && res[1] == '0' && \
		((attribute.field - attribute.prec) >= 2 || \
		flag[ft_strlen(flag) - 1] == 'p'))
			res[1] = 'x';
		else if (res[0] == '0' && res[1] != ' ' && \
		(attribute.field > attribute.prec || \
		flag[ft_strlen(flag) - 1] == 'p'))
		{
			res[0] = 'x';
			res = ft_strjoin_free("0", res, 2);
		}
		else
			res = ft_strjoin_free("0x", res, 2);
	}
	else if (i == 1)
	{
		res[0] = 'x';
		return (res = ft_strjoin_free("0", res, 2));
	}
	else
		ft_memcpy(&(res[i - 2]), "0x", 2);
	return (res);
}

char		*ft_printf_attribute_sharp(char *flag, char *res, char c, \
t_att attribute)
{
	int		i;

	i = 0;
	if (res)
	{
		if (c == 'o' && res[0] != '0')
			return (ft_strjoin_free("0", res, 2));
		else if (c == 'x' || c == 'X')
		{
			if (res[0] == '0' && res[1] == '\0')
				return (res);
			while (res[i] == ' ')
				i++;
			res = ft_apply_sharp(flag, res, i, attribute);
			i = ft_strlen(res) - 1;
			if (ft_strchr(flag, '-') && res[i] == ' ' && res[i - 1] == ' ')
				res[i - 1] = '\0';
			else if (ft_strchr(flag, '-') && res[i] == ' ')
				res[i] = '\0';
			return (res);
		}
	}
	return (res);
}

char		*ft_printf_attribute_space(char *res)
{
	if (res && !ft_strchr(res, '-'))
	{
		if (res[0] == '\0')
			return (ft_strdup(" \0"));
		if (*res == '0' && res[1] == '0')
			*res = ' ';
		else if (*res != ' ')
			return (ft_strjoin_free(" ", res, 2));
		else
			return (res);
	}
	return (res);
}
