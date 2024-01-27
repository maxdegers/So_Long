# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:32:21 by mbrousse          #+#    #+#              #
#    Updated: 2024/01/27 14:35:59 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	

OBJECTS	= 	${SOURCES:.c=.o}

HEADER			=	so_long.h

NAME			=	client

CC 				=	cc

FLAGS 			=	-Wall -Wextra -Werror

all: ${NAME}

%.o:%.c  ${HEADER} libft/libft.h
	${CC} ${FLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}: ${OBJECTS} Makefile
	make -C ./libft
	${CC} ${FLAGS} ${OBJECTS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -L./libft -lft

clean:
	make clean -C ./libft
	rm -f ${OBJECTS}

fclean: clean
	make fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re