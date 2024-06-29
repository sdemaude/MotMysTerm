# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 10:24:05 by sdemaude          #+#    #+#              #
#    Updated: 2024/06/24 10:57:16 by ccormon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJS = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror
PRINTF = printf

SRC = 	ft_atoi.c\
	ft_isprint.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strmapi.c\
	ft_toupper.c\
	ft_bzero.c\
	ft_itoa.c\
	ft_memset.c\
	ft_strdup.c\
	ft_strncmp.c\
	ft_calloc.c\
	ft_putchar_fd.c\
	ft_striteri.c\
	ft_strnstr.c\
	ft_isalnum.c\
	ft_lstnew.c\
	ft_putendl_fd.c\
	ft_strjoin.c\
	ft_strrchr.c\
	ft_isalpha.c\
	ft_memchr.c\
	ft_putnbr_fd.c\
	ft_strlcat.c\
	ft_strtrim.c\
	ft_isascii.c\
	ft_memcmp.c\
	ft_putstr_fd.c\
	ft_strlcpy.c\
	ft_substr.c\
	ft_isdigit.c\
	ft_memcpy.c\
	ft_split.c\
	ft_strlen.c\
	ft_tolower.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	gnl/get_next_line.c\
	gnl/get_next_line_utils.c

%.o: %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	ar crs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
