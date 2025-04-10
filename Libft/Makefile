# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Paths
SRC = src/
BNS = bonus/
INC = includes/

# Files (no extensions here)
SRC_FILES = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
BONUS_FILES = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

# Prefixed file paths with .c extension
SRCS = $(addsuffix .c, $(addprefix $(SRC), $(SRC_FILES)))
BONUS_SRCS = $(addsuffix .c, $(addprefix $(BNS), $(BONUS_FILES)))

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Output
NAME = libft.a

# Default target
all: $(NAME)

# Make libft.a from normal .o files
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile rule: .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

# Add bonus
bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

# Clean object files
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

# Clean everything
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus

