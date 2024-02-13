# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:32:21 by mbrousse          #+#    #+#              #
#    Updated: 2024/02/13 18:51:02 by mbrousse         ###   ########.fr        #
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

FLAGS 			=	-Wall -Wextra -Werror -g3 #-fsanitize=address

all: 
	@make --no-print-directory -C mlx_linux
	@make --no-print-directory -C ./libft
	@make --no-print-directory ${NAME}

${OBJ_D}:
	@mkdir -p ${OBJ_D}
	
${OBJECTS} : ${OBJ_D}%.o: ${SRC_D}%.c  ${HEADER} libft/libft.h Makefile libft/Makefile
	${CC} ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJ_D} ${OBJECTS} Makefile libft/libft.a
	$(CC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -L./libft -lft

clean:
	@make --no-print-directory clean -C ./libft
	@make --no-print-directory clean -C mlx_linux
	@rm -rf ${OBJ_D} 

fclean: clean
	@make --no-print-directory fclean -C ./libft
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re