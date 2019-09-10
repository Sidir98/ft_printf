# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 21:31:16 by ibouabda          #+#    #+#              #
#    Updated: 2019/09/09 13:13:55 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isprint.c ft_isdigit.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_memalloc.c \
		ft_lstmap.c ft_lstnew.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_itoa.c ft_putchar_fd.c ft_putendl.c \
		ft_putendl_fd.c ft_memccpy.c ft_putchar.c ft_putnbr.c ft_putstr_fd.c \
		ft_putstr.c ft_putnbr_fd.c ft_strcat.c ft_strclr.c ft_strchr.c ft_lstnewstr.c\
		ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strcmp.c ft_striter.c \
		ft_striteri.c ft_strlen.c ft_strjoin.c ft_strlcat.c ft_strmap.c ft_isalnum.c \
		ft_strncat.c ft_strncpy.c ft_strmapi.c ft_strncmp.c ft_strnequ.c ft_3dstrnew.c\
		ft_strnew.c ft_strrchr.c ft_strnstr.c ft_strstr.c ft_strsub.c ft_isalpha.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstlen.c ft_lstmanynew.c ft_2dstrnew.c\
		ft_strsplit.c ft_isascii.c ft_lstaddafter.c ft_lstaddend.c ft_putstrlst.c\
		ft_3dstrin.c ft_2dstrcmp.c ft_3dputstr.c ft_2dstrlen.c ft_3dstrlen.c ft_sqrt.c\
		ft_2dputstr.c ft_2dstrdel.c ft_sqrt_aprox.c ft_3dstrdel.c ft_size_t_del.c\
		ft_countnumbers.c ft_itoa_base.c ft_itoa_base_maj.c ft_lstadd.c ft_lstdellink.c\
		ft_lstdelm.c ft_lstnewc.c ft_putdouble.c ft_strchar.c ft_strrev.c ft_itoa_base_maj.c\
		ft_putnbr_count.c ft_strnstrdup.c ft_str2chr.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	gcc $(CFLAGS) -c $(SRC_NAME)
	ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJ_NAME)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
