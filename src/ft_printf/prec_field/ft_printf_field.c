/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:59:58 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 13:58:31 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_get_field(char *flag)
{
	char	*tmp;

	tmp = flag;
	while (!(*tmp >= '1' && *tmp <= '9') && *tmp && *tmp != '.')
		tmp++;
	if (*tmp >= '1' && *tmp <= '9')
		return (ft_atoi(tmp));
	else
		return (0);
}

char		*ft_printf_field_di(char *res, t_att attribute, char c)
{
	char	*tmp;
	int		i;

	if (attribute.field < 0)
		i = (-attribute.field - ft_strlen(res));
	else
		i = (attribute.field - ft_strlen(res));
	if (!*res)
		i = attribute.field;
	if (!ft_strchr(res, '-') && attribute.sign && attribute.minus)
		i--;
	if (i <= 0)
		return (res);
	if ((tmp = ft_strnew((size_t)i)))
	{
		while (i)
			tmp[--i] = c;
		if ((attribute.minus && attribute.field != 0) || attribute.field < 0)
			res = ft_strjoin_free(res, tmp, 3);
		else
			res = ft_strjoin_free(tmp, res, 3);
	}
	return (res);
}

static char	*ft_apply_field(char *flag, char *res, char *tmp, t_att att)
{
	if ((att.minus && att.field != 0) || att.field < 0)
	{
		if (!*res)
		{
			if (flag[ft_strlen(flag) - 1] == 's')
				tmp[ft_strlen(tmp) - 1] = '\0';
			else
				*tmp = *res;
			ft_strdel(&res);
			return ((res = tmp));
		}
		else
			return ((res = ft_strjoin_free(res, tmp, 3)));
	}
	if (!*res)
	{
		tmp[ft_strlen(tmp) - 1] = *res;
		ft_strdel(&res);
		res = tmp;
	}
	else
		res = ft_strjoin_free(tmp, res, 3);
	return (res);
}

char		*ft_printf_field(char *flag, char *res, t_att att, char c)
{
	char	*tmp;
	int		i;

	if (att.field < 0)
		i = (-att.field - ft_strlen(res));
	else
		i = (att.field - ft_strlen(res));
	if (!*res)
		i = att.field;
	if (att.sign && att.minus)
		i--;
	if (att.nullchar == 0 && res[0] == '\0')
		i++;
	if (i <= 0)
		return (res);
	if ((tmp = ft_strnew((size_t)i)))
	{
		while (i)
			tmp[--i] = c;
		res = ft_apply_field(flag, res, tmp, att);
	}
	return (res);
}
