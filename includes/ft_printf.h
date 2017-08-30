/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:08:19 by vsporer           #+#    #+#             */
/*   Updated: 2017/08/19 14:08:22 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"
# include "ft_printf_struct.h"

t_index	ft_printf_search_prec(char *flag, char **clean_flag, t_index index, \
va_list *ap);
t_index	ft_printf_search_field(char *flag, char **clean_flag, t_index index, \
va_list *ap);
t_list	*ft_printf_tolst(char *format, int *nullchar, va_list *ap);
t_list	*ft_get_flag(const char *format);
size_t	ft_printf_skip_nullchar(char *str, int nbnullchar);
t_att	ft_printf_start_struct(char *flag);
t_att	ft_printf_load_struct(char *flag, va_list *ap);
t_att	ft_printf_clear_flag(char *flag, va_list *ap);
t_att	ft_printf_switch(char *flag, va_list *ap);
char	*ft_conv_c(char *flag, va_list *ap, t_att *attribute);
char	*ft_conv_di(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_o(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_b(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_u(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_xp_xup(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_lc_cup(char *flag, va_list *ap, t_att *attribute);
char	*ft_conv_ls_sup(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_s(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_percent(char *flag, t_att attribute);
char	*ft_conv_p(char *flag, va_list *ap, t_att attribute);
char	*ft_conv_not_valid(char *flag, t_att attribute);
char	*ft_printf_field(char *flag, char *res, t_att att, char c);
char	*ft_printf_field_di(char *res, t_att att, char c);
char	*ft_printf_prec(char *flag, char *res, int prec_value);
char	*ft_printf_prec_s(char *res, int prec_value);
char	*ft_printf_lenmod_i(char *flag, va_list *ap, int i);
char	*ft_printf_lenmod_ui(char *flag, va_list *ap, int i, int base);
char	*ft_printf_attribute_space(char *res);
char	*ft_printf_attribute_sharp(char *flag, char *res, char c, \
		t_att attribute);
char	ft_printf_attribute_zero(t_att attribute);
char	ft_printf_attribute_zero_char(t_att attribute);
char	ft_printf_attribute_zero_num(t_att attribute);
char	*ft_printf_attribute_sign(char *res, t_att attribute);
char	*ft_printf_attribute_sign_di(char *res, t_att attribute);
int		ft_isattribute(char c);
int		ft_islenmod(char c);
int		ft_printf_search_conv(char *flag, int i);
int		ft_printf_get_field(char *flag);
int		ft_printf_get_prec(char *flag);
int		ft_printf_get_zero(char *flag);
int		ft_printf_get_minus(char *flag);
int		ft_asprintf(char **ret, const char *format, ...);
int		ft_fprintf(FILE *stream, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
