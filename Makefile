# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 10:56:30 by aarranz-          #+#    #+#              #
#    Updated: 2024/03/26 17:09:35 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
# -Imlx abajo
CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -fsanitize=address
RM = /bin/rm -rf

LIBFT = libs/libft/
GNL = libs/get_next_line/

SRC_PATH	=	src/
SRC =	so_long.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL)
#	$(MAKE) -C $(MLX) 2> /dev/null
	cp $(LIBFT)libft.a ./
	cp $(GNL)get_next_line.a ./
#	cp $(MLX)libmlx.a ./
# -Lmlx -framework OpenGL -framework AppKit libmlx.a abajo
	$(CC) -o $(NAME) $(OBJ) libft.a get_next_line.a
#	echo "$$SO_LONG"

$(OBJ): $(SRC_PATH)$(SRC)
	$(CC) $(CFLAGS) -c $(SRC_PATH)$(SRC)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(GNL) clean
#	$(MAKE) -C $(MLX) clean
	echo "objs deleted"

fclean: clean
	$(RM) $(NAME) libft.a get_next_line.a 
#	libmlx.a arriba
	echo "executable deleted"

re: fclean all

.PHONY: all clean fclean re
