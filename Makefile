# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/09 20:54:30 by kkuvalis          #+#    #+#              #
#    Updated: 2019/05/22 19:13:10 by kkuvalis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC  = fractal.c draw.c hookone.c hooktwo.c mandelbrot.c julia.c ship.c 

OBJ  = $(SRC:.c=.o)

FLAGS =  -g -Wall -Werror -Wextra

FLAGS_MLX = /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

INC_LIB = libft

HEAD = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -I$(INC_LIB) -o $(NAME) -lpthread  -L $(FLAGS_MLX)
	
$(LIBFT):
	make -C libft/

%.o : %.c fractal.h 
	gcc $(FLAGS) -c $< -o $@ -I$(INC_LIB)

clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all
	make -C libft re
