
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 22:59:15 by nkim              #+#    #+#              #
#    Updated: 2022/02/17 17:32:27 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES_DIR = include

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AFLAGS = rus

LIBFT_DIR = libft
FTPRINTF_DIR = ft_printf
GNL_DIR = get-next-line

LIBFT	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_ptr_realloc.c ft_realloc.c

FTPRINTF	= ft_printf.c print_number.c print_string.c utils.c

GNL	= get_next_line.c get_next_line_utils.c

all : $(NAME)

clean :
	rm -rf $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
	rm -rf $(addprefix $(FTPRINTF_DIR)/, $(FTPRINTF:.c=.o))
	rm -rf $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

fclean : clean
	rm -rf $(NAME)

re : fclean all

$(NAME): libft ft_printf gnl

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT:.c=.o))
ft_printf: $(addprefix $(FTPRINTF_DIR)/, $(FTPRINTF:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))


.PHONY : all clean fclean re
