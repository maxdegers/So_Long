# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:32:21 by mbrousse          #+#    #+#              #
#    Updated: 2024/02/13 15:31:45 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	so_long.c\
			so_long_utils.c\
			error.c\
			checker.c\
			tab_utils.c\
			checker_utils.c

OBJ_D	= objs/

SRC_D	= src/

OBJECTS = ${SOURCES:%.c=${OBJ_D}%.o}

HEADER 	=	includes/so_long.h

H_D 	= 	.


NAME			=	so_long

CC 				=	cc

FLAGS 			=	-Wall -Wextra -Werror -g3

all: 
	@make --no-print-directory -C ./libft
	@make --no-print-directory ${NAME}

%.o:%.c  ${HEADER} libft/libft.h
	${CC} ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJECTS} Makefile
	make -C ./libft
	make -C mlx_linux
	$(CC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	make clean -C mlx_linux
	rm -f ${OBJECTS}

fclean: clean
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re