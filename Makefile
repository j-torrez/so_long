# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johnbosco <johnbosco@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 13:44:52 by arommers          #+#    #+#              #
#    Updated: 2023/08/29 14:20:28 by johnbosco        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT = so long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long
LIBFT = ./Libft/libft.a
MLX42 = ../../MLX42/build/libmlx42.a
INCLUDE = -I./include
SRC = SRC/main.c SRC/parse_map.c   /
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

BOLD    := \033[1m./SRC/
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)	
	@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42) $(MLX42FLAGS)
	@echo "$(CYAN)-------------------------------------------"
	@echo "	$(NAME) = NOW READY FOR USE!"
	@echo "-------------------------------------------$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./Libft

$(MLX42):
	@$(MAKE) -C ./MLX42

$(OBJ_DIR)/%.o: ./SRC/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiled ✅ $(CYAN) $^ $(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./Libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./Libft
	@rm -f $(NAME)
	@echo "$(GREEN) $(PROJECT) $(RESET) Cleaned ✅"

re: fclean all

.PHONY: all clean fclean re