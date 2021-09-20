# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 22:59:15 by nkim              #+#    #+#              #
#    Updated: 2021/08/13 15:58:37 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
AFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror
SRCS = *.c
SRC	=	ft_strlen.c
OBJ	=	$(SRC:.c=.o)
OBJECTS = $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)

test :
	$(CC) $(CFLAGS) ft_printf.c -L $(NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all


$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $?
	
.PHONY : all clean fclean re 