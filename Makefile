# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cress <cress@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 19:47:37 by cress             #+#    #+#              #
#    Updated: 2025/08/07 22:57:28 by cress            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MINI_DIR)
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MINI_DIR = ./minilibx
MINILIBX = $(MINI_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm -lbsd

NAME_S = so_long
SRC_S = main.c game_utils.c load_images.c draw_walls_floor.c draw_player_exit.c parsing.c parsing2.c moves.c moves2.c
OBJ_S = $(SRC_S:.c=.o)

all: $(NAME_S)

$(NAME_S): $(LIBFT) $(MINILIBX) $(OBJ_S)
	@echo "Creando $(NAME_S)"
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME_S)

$(LIBFT):
	@echo "Compilando libft..."
	make -C $(LIBFT_DIR)

$(MINILIBX):
	@echo "Compilando minilibx..."
	make -C $(MINI_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_S)
	make -C $(LIBFT_DIR) clean
	make -C $(MINI_DIR) clean

fclean: clean
	$(RM) $(NAME_S)
	make -C $(LIBFT_DIR) fclean
	make -C $(MINI_DIR) clean

re: fclean all

.PHONY: all clean fclean re
