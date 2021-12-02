#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"
// #include "gnl/get_next_line.h"

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
	int position[2]; // координаты игрока
} t_elements;

t_elements *parse(int argc, char **argv);

void	init_empty_elem(t_elements *elem);
void	check_texture(char **elem_line, char **elem_name);
int 	check_colors(char **elem_line, int *elem_values, char *elem_name);
int		record_elem(char *line, t_elements *elem, int *num);
int record_map(char *line, char **map);

int msg_wrong_argc(void);
int msg_error(char *name);
int msg_wrong_elem_args(char *str);
int msg_elem_dublicates(char *str);
int msg_malloc_fail(void);
int msg_wrong_rgb(char *name);
int msg_invalid_line(char *name);
int msg_map_last(void);
int msg_map_wrong(void);

int array2_len(char **array2);
void array2_free(char **array2);

int is_digitstr(char *str);
int sym_found(char *str, char *search);

#endif