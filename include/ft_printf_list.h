/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:47:28 by vsporer           #+#    #+#             */
/*   Updated: 2019/08/12 12:23:59 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIST_H
# define FT_PRINTF_LIST_H

# include <unistd.h>

typedef struct	s_index
{
	int		i;
	int		j;
}				t_index;

typedef struct	s_ftplst
{
	int				flag_ok;
	int				sharp;
	int				zero;
	int				minus;
	int				space;
	int				sign;
	int				field;
	int				prec;
	int				nullchar;
	char			*arg;
	char			*flag;
	char			*clean_flag;
	size_t			size;
	t_index			index;
	struct s_ftplst	*next;
}				t_ftplst;

t_ftplst		*ft_ftplstnew(char *flag);
void			ft_ftplstaddback(t_ftplst **alst, t_ftplst *new_node);
void			ft_ftplstdel(t_ftplst **todel);

#endif
