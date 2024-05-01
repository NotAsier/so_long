# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:33:45 by aarranz-          #+#    #+#              #
#    Updated: 2024/05/01 17:41:26 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long
SRC_PATH	:=	src
OBJ_DIR		:=	obj
SOURCES		:=	so_long.c map_checker.c map_checker2.c mlx.c movements.c
OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I./include -Imlx -g3 #-fsanitize=address

LIBFT = libs/libft/
GNL = libs/get_next_line/
MLX = mlx/

PAPYRUS=\033[38;5;223m
END=\033[0m

define SO_LONG
$(PAPYRUS)
                        .="=.
                      _/.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .--------.       \'---'/    //
     _|Benancio|_      /`"""`\\  ((
   =(_|________|_)=   / /_,_\ \\  \\\\
     |:::::::::|      \_\\_'__/ \  ))
     |:::::::[]|       /`  /`~\  |//
     |o=======.|      /   /    \  /
      `"""""""""`  ,--`,--'\/\    /
                   '-- "--'  '--'
$(END)
endef
export SO_LONG

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL)
	$(MAKE) -C $(MLX) 2> /dev/null
	mv $(LIBFT)libft.a ./
	mv $(GNL)get_next_line.a ./
	mv $(MLX)libmlx.a ./
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -Lmlx -framework OpenGL -framework AppKit libmlx.a libft.a get_next_line.a
	@echo "$$SO_LONG"

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