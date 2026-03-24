# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nellys-simulation <nellys-simulation@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:15:34 by mayahiao          #+#    #+#              #
#    Updated: 2026/03/24 22:19:18 by nellys-simu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#copied from my printf project and adjusted
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror  -Wno-cast-function-type #remove the who before uploading, just to suppress from own pc
RM = rm -f

SRC_FILES = get_next_line get_next_line_utils is_map_accessible is_map_valid is_map_valid_2 is_map_valid_3 main map_parsing_drawing map_parsing_drawing_2 movement window_management
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

