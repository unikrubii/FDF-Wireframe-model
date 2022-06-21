# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:48:41 by sthitiku          #+#    #+#              #
#    Updated: 2022/06/21 23:29:27 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 	fdf_parse_map.c fdf_free.c fdf_draw.c fdf_error.c fdf_utils.c \
		fdf_draw_utils.c fdf_init.c fdf_key_draw.c main.c
# SRCS = fdf_parse_map.c fdf_free.c fdf_bresenham.c fdf_error.c fdf_utils.c
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
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = incs/
HEADER = fdf.h key.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS)) $(addprefix $(INCS_DIR), $(HEADER))
	@make -C $(LIBFT_DIR) --silent
	@make -C $(MLX_DIR) --silent
	$(CC) $(addprefix $(OBJS_DIR), $(OBJS)) -o $(NAME) -L $(LIBFT_DIR) -lft $(MLX_FLAGS)
	@echo MAKE!!

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR) --silent
	@$(RM) $(OBJS_DIR)
	@echo CLEAN!!

fclean: clean
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)
	@echo FCLEAN!!

re: fclean all

fun: re
	@./$(NAME) test_maps/42.fdf

leak: all
	@valgrind --leak-check=full ./$(NAME) test_maps/42.fdf

.PHONY: all clean fclean re
