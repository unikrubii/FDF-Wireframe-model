# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:48:41 by sthitiku          #+#    #+#              #
#    Updated: 2022/06/13 20:51:44 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = parse_map.c
OBJS = $(SRCS:.c=.o)

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_DIR		= mlx_Linux
	MLX_FLAGS	= -Imlx_Linux -Lmlx_Linux -lmlx_Linux -lXext -lX11 -lm -lz
	INCLUDES 	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(PRINTF_DIR) \
				  -I/usr/include
	LIBS		= -L$(LIBFT_DIR) -lft \
				  -L$(PRINTF_DIR) -lftprintf \
				  -L/usr/lib 
else
	MLX_DIR		= mlx
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	INCLUDES 	= -I$(INCLUDE_DIR) \
				  -I$(LIBFT_DIR) \
				  -I$(PRINTF_DIR) \
				  -I$(MLX_DIR)
	LIBS		= -L$(LIBFT_DIR) -lft \
				  -L$(PRINTF_DIR) -lftprintf
endif

LIBFT_DIR = libft/
HEADER = fdf.h

CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@make -C $(LIBFT_DIR) --silent
	@make -C $(MLX_DIR) --silent
	$(CC) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft $(MLX_FLAGS)
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
	@./$(NAME) test_maps/42.fdf

.PHONY: all clean fclean re
