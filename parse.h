#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct s_elements
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	int F[3];		 // цвет пола
	int C[3];		 // цвет потолка
	char direct;	 // напрвление игрока, W запад, E восток,  N север, S юг
	char **map;		 // сама карта
	int position[2]; // координаты игрока в 2мерном массиве
	int width; //ширина карты
	int height; // высота карты
} t_elements;

t_elements *parse(int argc, char **argv);

void	init_empty_elem(t_elements *elem);
void	check_texture(char **elem_line, char **elem_name);
int 	check_colors(char **elem_line, int *elem_values, char *elem_name);
int		record_elem(char *line, t_elements *elem, int *num);
int record_map(char *line, char **map);
int validate_map(t_elements *elem, char *line);


int msg_error(char *name);
int msg_malloc_fail(void);
int msg_err2(char *name, char *text);
int msg_map_last(void);
int msg_err(char *str);


int array2_len(char **array2);
void array2_free(char **array2);
char **create_array2(t_elements *elem);
void fill_map(char *map, char **map_arr, int x, int y);



int is_digitstr(char *str);
int sym_found(char *str, char *search);

#endif