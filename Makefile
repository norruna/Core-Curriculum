# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:15:34 by mayahiao          #+#    #+#              #
#    Updated: 2026/03/23 15:31:32 by mayahiao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#copied from my printf project and adjusted
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_FILES = get_next_line get_next_line_utils is_map_accessible is_map_valid main map_parsing_drawing movement window_management
SRCS = $(addsuffix .c, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

all: minilibx-linux/libmlx.a $(NAME)

$(NAME): $(OBJS) minilibx-linux/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx -lX11 -lXext -o $(NAME)

minilibx-linux/libmlx.a:
	$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C minilibx-linux clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

