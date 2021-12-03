#ifndef PARSE_H
#define PARSE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"
#include "minilibx_opengl/mlx.h"

#define HEIGHT 480
#define WIDTH 640

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}				t_keys;

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		texx;
	int		texy;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	step;
	double	texpos;
}			t_ray;

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

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}			t_player;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_texture
{
	t_vector	size;
	int			size_line;
	int			endian;
	int			bpp;
	void		*img;
	char		*addr;
}				t_texture;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_coords
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_coords;

typedef struct s_cube
{
	void		*mlx;
	void		*win;

	t_img		*img;
	t_elements	*src;
	t_coords	*coords;
	t_texture	*texs;
	t_player	*hero;
	t_keys		*key;
}				t_cube;

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

// graphic

void	graphic(t_cube *cube);
void	draw(t_cube *cube);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_walls(t_cube *cube);
void	move(t_cube *cube);

#endif