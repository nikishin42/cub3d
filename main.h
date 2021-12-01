#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <math.h>

#include "libft/libft.h"
#include "minilibx_opengl/mlx.h"
#include "graphic/graphic.h"

typedef struct s_elements
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	int F[3];		 // 3 цвета пола 
	int C[3];		 // цвет потолка
	char direct;	 // напрвление игрока, W запад, E восток,  N север, S юг
	char **map;		 // сама карта
	int position[2]; // координаты игрока
} t_elements;


t_elements *parse(int argc, char **argv);
int	msg_wrong_argc(void);


#endif