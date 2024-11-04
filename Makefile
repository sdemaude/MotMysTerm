# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdemaude <sdemaude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 17:41:22 by sdemaude          #+#    #+#              #
#    Updated: 2024/11/04 16:14:01 by sdemaude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= MotMysTerm 

CC 			= cc
RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror 
CLINKS		= -lreadline

LIBFTDIR	= lib/libft
LIBFT		= $(LIBFTDIR)/libft.a

SRCDIR		= src
SRCFILE		= main\
			  list_utils\
			  display\
			  init\
			  input\
			  game_logic

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