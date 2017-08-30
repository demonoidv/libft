/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:47:28 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:07:40 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

# include "ft_printf.h"

typedef struct	s_attribute
{
	char	*arg;
	char	*clean_flag;
	int		flag_ok;
	int		sharp;
	int		zero;
	int		minus;
	int		space;
	int		sign;
	int		field;
	int		prec;
	int		nullchar;
}				t_att;

typedef struct	s_index
{
	int		i;
	int		j;
}				t_index;

#endif
