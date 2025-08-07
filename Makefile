# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = include
CFLAGS += -I$(INCLUDE_DIR)

# Target file
NAME = ft_ping

# Source files
SRCS = ./src/ft_ping.c \
			 ./src/pars.c


# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Clean rule
clean:
	rm -f $(OBJS)

# Full clean rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

# PHONY targets
.PHONY: all clean fclean re

