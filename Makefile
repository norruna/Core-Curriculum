# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:15:34 by mayahiao          #+#    #+#              #
#    Updated: 2025/11/15 14:15:35 by mayahiao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#copied from my printf project and adjusted
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_FILES = push_swap radix parse_args instructions instructionsV2

SRCS = $(addsuffix .c, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all:
	$(MAKE) -C Libft all
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re bonus

