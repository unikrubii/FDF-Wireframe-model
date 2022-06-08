# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 12:48:41 by sthitiku          #+#    #+#              #
#    Updated: 2022/06/08 12:59:48 by sthitiku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = parse_map.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft/
HEADER = fdf.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@make -C $(LIBFT_DIR) --silent
	@$(CC) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft
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

.PHONY: all clean fclean re
