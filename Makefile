# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsporer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:51:49 by vsporer           #+#    #+#              #
#    Updated: 2017/05/02 15:12:57 by vsporer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

INCLUDES =	includes/
PATH_BASE =	src/
PATH_OBJ =	obj/

SRCS = 		$(PATH_BASE)ft_atoi.c\
			$(PATH_BASE)ft_bzero.c\
			$(PATH_BASE)ft_isalnum.c\
			$(PATH_BASE)ft_isalpha.c\
			$(PATH_BASE)ft_isascii.c\
			$(PATH_BASE)ft_isdigit.c\
			$(PATH_BASE)ft_isprint.c\
			$(PATH_BASE)ft_memalloc.c\
			$(PATH_BASE)ft_memccpy.c\
			$(PATH_BASE)ft_memchr.c\
			$(PATH_BASE)ft_memcmp.c\
			$(PATH_BASE)ft_memcpy.c\
			$(PATH_BASE)ft_memdel.c\
			$(PATH_BASE)ft_memmove.c\
			$(PATH_BASE)ft_memset.c\
			$(PATH_BASE)ft_putchar.c\
			$(PATH_BASE)ft_putnbr.c\
			$(PATH_BASE)ft_putstr.c\
			$(PATH_BASE)ft_strcat.c\
			$(PATH_BASE)ft_strchr.c\
			$(PATH_BASE)ft_strclr.c\
			$(PATH_BASE)ft_strcmp.c\
			$(PATH_BASE)ft_strcpy.c\
			$(PATH_BASE)ft_strdel.c\
			$(PATH_BASE)ft_strdup.c\
			$(PATH_BASE)ft_strequ.c\
			$(PATH_BASE)ft_striter.c\
			$(PATH_BASE)ft_striteri.c\
			$(PATH_BASE)ft_strjoin.c\
			$(PATH_BASE)ft_strlcat.c\
			$(PATH_BASE)ft_strlen.c\
			$(PATH_BASE)ft_strmap.c\
			$(PATH_BASE)ft_strmapi.c\
			$(PATH_BASE)ft_strncat.c\
			$(PATH_BASE)ft_strncmp.c\
			$(PATH_BASE)ft_strncpy.c\
			$(PATH_BASE)ft_strnequ.c\
			$(PATH_BASE)ft_strnew.c\
			$(PATH_BASE)ft_strnstr.c\
			$(PATH_BASE)ft_strrchr.c\
			$(PATH_BASE)ft_strstr.c\
			$(PATH_BASE)ft_strsub.c\
			$(PATH_BASE)ft_strtrim.c\
			$(PATH_BASE)ft_tolower.c\
			$(PATH_BASE)ft_toupper.c\
			$(PATH_BASE)ft_strsplit.c\
			$(PATH_BASE)ft_itoa.c\
			$(PATH_BASE)ft_putendl.c\
			$(PATH_BASE)ft_putchar_fd.c\
			$(PATH_BASE)ft_putstr_fd.c\
			$(PATH_BASE)ft_putendl_fd.c\
			$(PATH_BASE)ft_putnbr_fd.c\
			$(PATH_BASE)ft_lstadd.c\
			$(PATH_BASE)ft_lstdel.c\
			$(PATH_BASE)ft_lstdelone.c\
			$(PATH_BASE)ft_lstiter.c\
			$(PATH_BASE)ft_lstmap.c\
			$(PATH_BASE)ft_lstnew.c\
			$(PATH_BASE)ft_ulltoa_base.c\
			$(PATH_BASE)ft_strjoin_free.c\
			$(PATH_BASE)ft_strsubstitute.c\
			$(PATH_BASE)ft_countchar.c\
			$(PATH_BASE)ft_wcharlen.c\
			$(PATH_BASE)ft_wcrtomb.c\
			$(PATH_BASE)ft_wcsrlen.c\
			$(PATH_BASE)ft_wcsrtombs.c\
			$(PATH_BASE)ft_putstr_minlen.c\
			$(PATH_BASE)ft_strstr_minlen.c\
			$(PATH_BASE)ft_lstaddback.c

OBJ =		$(patsubst $(PATH_BASE)%.c, $(PATH_OBJ)%.o, $(SRCS))

CC =		gcc -Wall -Wextra -Werror
CCI =		-I includes/

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling libft.a"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Done !"

$(PATH_OBJ)%.o : $(PATH_BASE)%.c
	@mkdir -p $(@D)
	@echo "Compiling $< to $@"
	@$(CC) $(CCI) -c $< -o $@

.PHONY: clean

clean:
	@rm -rf $(PATH_OBJ)
	@echo "Clean all .o : Done"

fclean: clean
	@rm -rf $(NAME)
	@echo "Delete libft.a : Done"

re: fclean all
