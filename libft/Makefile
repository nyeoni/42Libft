# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 22:59:15 by nkim              #+#    #+#              #
#    Updated: 2021/05/03 22:59:31 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXEX : .c .o
NAME = libft.a
CC = gcc
AFLAGS = rc
CFLAGS = -Wall -Wextra -Werror
SRCS = *.c
OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $@ $?
%.o : %.c
	$(CC) $(CFLAGS) -c $?
.PHONY : all clean fclean re
