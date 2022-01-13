/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstarmie <cstarmie@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:24:24 by cstarmie          #+#    #+#             */
/*   Updated: 2022/01/05 22:24:34 by cstarmie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

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
	int	x;
	int	y;
}	t_vector;

typedef struct s_elements
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			fl[3];
	int			cl[3];
	char		dir;
	char		**map;
	t_vector	vec;
	int			width;
	int			height;
}	t_elements;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

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

t_elements		*parse(int argc, char **argv);
void			init_empty_elem(t_elements *elem);
void			check_texture(char **elem_line, char **elem_name);
int				check_colors(char **elem_line, int *elem_vals, char *elem_nm);
char			*read_map(int fd, t_elements *elem, char **map);
int				record_elem(char *line, t_elements *elem, int *num);
int				validate_map(t_elements *elem, char *line);
int				check_start_point(char **map, t_elements *elem);
void			check_walls(char **map_arr, t_elements *elem);

int				msg_stderror(char *name);
int				msg_malloc_fail(void);
int				msg_err2(char *name, char *text);
int				msg_map_last(void);
int				msg_err(char *str);
int				msg_walls_err(int i, int j);

int				array2_len(char **array2);
void			array2_free(char **array2);
char			**create_array2(t_elements *elem);
void			fill_map(char *map, char **map_arr, int x, int y);

int				is_digitstr(char *str);
int				sym_found(char *str, char *search);

char			*ft_strdupc(char *s1, char c);
int				get_next_line(int fd, char **line);

void			graphic(t_cube *cube);
void			draw(t_cube *cube);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			draw_walls(t_cube *cube);
void			move(t_cube *cube);
int				draw_all(t_cube *cube);
unsigned long	color_hex(int r, int g, int b);
void			rot_right(t_cube *cube);
void			rot_left(t_cube *cube);
int				closer();
void			draw_stripe(t_cube *cube, int x, t_ray *ray);
void			line_height(t_ray *ray);
void			dda(t_cube *cube, t_ray *ray);
void			step_sidedist_init(t_cube *cube, t_ray *ray);
void			ray_init(t_cube *cube, int x, t_ray *ray);
void			texturing(t_cube *cube, t_ray *ray, int x);
void			apply_pixel(t_img *img, int x, int y, int color);
unsigned long	color_hex(int r, int g, int b);
void			set_plane(t_cube *cube);
void			set_direction(t_cube *cube);
int				key_press(int key, t_cube *cube);
int				key_release(int key, t_cube *cube);

#endif
