# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:15:34 by mayahiao          #+#    #+#              #
#    Updated: 2025/11/17 04:54:56 by mayahiao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#copied from my printf project and adjusted
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_FILES = indexing instructionsV3 misc misc2 sort_five sorting push_swap radix parse_args instructions instructionsV2

SRCS = $(addsuffix .c, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: Libft/libft.a $(NAME)

$(NAME): $(OBJS) Libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

Libft/libft.a:
	$(MAKE) -C Libft all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re

