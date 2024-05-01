# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:33:45 by aarranz-          #+#    #+#              #
#    Updated: 2024/05/01 10:21:34 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long
SRC_PATH	:=	src
OBJ_DIR		:=	obj
SOURCES		:=	so_long.c map_checker.c map_checker2.c mlx.c
OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I./include -Imlx -g3 #-fsanitize=address

LIBFT = libs/libft/
GNL = libs/get_next_line/
MLX = mlx/

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL)
	$(MAKE) -C $(MLX) 2> /dev/null
	mv $(LIBFT)libft.a ./
	mv $(GNL)get_next_line.a ./
	mv $(MLX)libmlx.a ./
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Lmlx -framework OpenGL -framework AppKit libmlx.a libft.a get_next_line.a

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -fr $(OBJ_DIR)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(GNL) clean
	$(MAKE) -C $(MLX) clean

fclean:
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(GNL) fclean
	$(MAKE) -C $(MLX) clean
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME) libft.a get_next_line.a libmlx.a

re: fclean all

.PHONY: all clean fclean re