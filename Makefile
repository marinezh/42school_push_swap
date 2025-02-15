# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 14:19:08 by mzhivoto          #+#    #+#              #
#    Updated: 2025/02/15 16:21:13 by mzhivoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = push_swap
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/

SRCS_PATH = ./src
OBJS_PATH = ./obj
LIBFT_PATH = ./libft

# Source files and object files
SRC = $(SRCS_PATH)/main.c \
	$(SRCS_PATH)/parse_input.c \
	$(SRCS_PATH)/helpers_function.c \
	$(SRCS_PATH)/sorting2.c \
	$(SRCS_PATH)/moves_ps.c \
	$(SRCS_PATH)/moves_reverse.c \
	$(SRCS_PATH)/moves_rotate.c \

OBJ := $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRC))

# Default rule to create the library
all: $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

# Compile each .c file into a .o file
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@


# Clean rule to remove object files and the library
clean:
	rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
