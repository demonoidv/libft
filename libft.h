/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:35:39 by vsporer           #+#    #+#             */
/*   Updated: 2016/11/07 15:49:02 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
size_t	ft_strlen(char const *s);
char	*ft_strdup(char const *s);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(const char *big, const char *little);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t n);
void	*ft_memccpy(void *dest, void *src, int c, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_memchr(void *s, int c, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));


#endif
