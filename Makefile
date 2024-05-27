# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudaniel <gudaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 10:10:40 by gudaniel          #+#    #+#              #
#    Updated: 2024/05/27 10:44:31 by gudaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = get_next_line.c  get_next_line_utils.c

OBJS = $(SRC:.c=.o)

COMPILER = cc
FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): 
		$(COMPILER) $(FLAGS) -c $(SRC)
		ar rcs $(NAME) $(OBJS)

re:		fclean $(NAME)

clean: 
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)