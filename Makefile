# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 17:41:22 by sdemaude          #+#    #+#              #
#    Updated: 2024/06/29 13:14:20 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= prog 

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		= -Wall -Wextra -Werror -g
CLINKS		= -ldl -lglfw -pthread -lm

LIBFTDIR	= lib/libft
LIBFT		= $(LIBFTDIR)/libft.a

SRCDIR		= src
SRCFILE		= main\
		  display

SRC 		= $(addprefix $(SRCDIR)/,$(addsuffix .c,$(SRCFILE)))

OBJDIR		= obj
OBJ 		= $(addprefix $(OBJDIR)/,$(addsuffix .o,$(SRCFILE)))

all: $(OBJDIR) $(NAME)

$(LIBFT): $(LIBFTDIR)
		make -C $(LIBFTDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(CLINKS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)
	$(RM) -r $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

c: all clean

.PHONY:		all bonus clean fclean re c
