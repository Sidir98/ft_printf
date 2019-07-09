# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 16:31:01 by ibouabda          #+#    #+#              #
#    Updated: 2019/07/09 16:37:48 by ibouabda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRC_NAME = ft_printf.c scpf.c uoxX.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	gcc $(CFLAGS) $(SRC_NAME) libft/libft.a
clean:
	/bin/rm -f $(OBJ_NAME)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all