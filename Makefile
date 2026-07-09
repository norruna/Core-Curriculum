# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/28 21:24:46 by nellys-simu       #+#    #+#              #
#    Updated: 2026/07/07 16:32:24 by mayahiao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
RDLNFLAGS = -lreadline -lncurses

SRC_FILES = minishell tokenizer cleanup run_command
SRCS = $(addsuffix .c, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  $(RDLNFLAGS) -o $(NAME)  

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
