# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:48:41 by sthitiku          #+#    #+#              #
#    Updated: 2022/06/09 21:18:20 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = parse_map.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft/
MLX_DIR = mlx/
HEADER = fdf.h

CC = gcc
# CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@make -C $(LIBFT_DIR) --silent
	@make -C $(MLX_DIR) --silent
	@$(CC) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft $(MLX_FLAGS)
	@echo MAKE!!

clean:
	@make clean -C $(LIBFT_DIR) --silent
	@$(RM) $(OBJS)
	@echo CLEAN!!

fclean:
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)
	@echo FCLEAN!!

re: fclean all

run: re
	@./$(NAME) 42.fdf

.PHONY: all clean fclean re
