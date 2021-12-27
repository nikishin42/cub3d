#ifndef PARSE_H
# define PARSE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <string.h>
#include "../libft/libft.h"
#include "../minilibx_opengl/mlx.h"

# define BUFFER_SIZE 1000
# define TEX 64
# define HEIGHT 480
# define WIDTH 640
# define MS 0.02
# define RS 0.03

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
}				t_keys;

typedef struct s_ray
{
	int		hit;
	int		side;
	double	step;
	int		texy;
	int		texx;
	int		mapy;
	int		mapx;
	int		stepy;
	int		stepx;
	int		color;
	double	texpos;
	int		drawend;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	sidedistx;
	double	sidedisty;
	int		drawstart;
	double	deltadisty;
	double	deltadistx;
	int		lineheight;
	double	perpwalldist;
}			t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}			t_player;

typedef struct s_vector
{
	int x;
	int y;
} t_vector;

typedef struct s_elements
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	int F[3];
	int C[3];
	char dir;
	char **map;
	t_vector vec;
	int width;
	int height;
} t_elements;

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

typedef struct s_texture
{
	t_vector	size;
	int			size_line;
	int			endian;
	int			bpp;
	void		*img;
	char		*addr;
}				t_texture;

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

t_elements	*parse(int argc, char **argv);

void	init_empty_elem(t_elements *elem);
void	check_texture(char **elem_line, char **elem_name);
int	check_colors(char **elem_line, int *elem_values, char *elem_name);
char	*read_map(int fd, t_elements *elem, char **map);
int	record_elem(char *line, t_elements *elem, int *num);
int	validate_map(t_elements *elem, char *line);
int	check_start_point(char **map, t_elements *elem);
void	check_walls(char **map_arr, t_elements *elem);

int	msg_stderror(char *name);
int	msg_malloc_fail(void);
int	msg_err2(char *name, char *text);
int	msg_map_last(void);
int	msg_err(char *str);
int	msg_walls_err(int i, int j);

int	array2_len(char **array2);
void	array2_free(char **array2);
char	**create_array2(t_elements *elem);
void	fill_map(char *map, char **map_arr, int x, int y);

int	is_digitstr(char *str);
int	sym_found(char *str, char *search);

char *ft_strdupc(char *s1, char c);
int get_next_line(int fd, char **line);

void	graphic(t_cube *cube);
void	draw(t_cube *cube);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_walls(t_cube *cube);
void	move(t_cube *cube);
int		draw_all(t_cube *cube);
unsigned long	color_hex(int r, int g, int b);
void	rot_right(t_cube *cube);
void	rot_left(t_cube *cube);
int	closer(t_cube *cube);
void	draw_stripe(t_cube *cube, int x, t_ray *ray);
void	line_height(t_cube *cube, t_ray *ray);
void	dda(t_cube *cube, t_ray *ray);
void	step_sidedist_init(t_cube *cube, t_ray *ray);
void	ray_init(t_cube *cube, int x, t_ray *ray);
void	texturing(t_cube *cube, t_ray *ray, int x);
void	apply_pixel(t_img *img, int x, int y, int color);
unsigned long color_hex(int r, int g, int b);

#endif