# SRC = graphic/*.c parser/*.c main.c 

SRC = main.c

NAME = cub3d

LIB = libft/libft.a

all:
	gcc $(SRC) $(LIB) -o $(NAME)