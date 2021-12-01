#ifndef graphic_H
#define graphic_H

#define RES_X 640
#define RES_Y 480

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_hero
{
	double			angle;
	t_vector		dir;
	t_vector		pos;
	t_vector		plane;
	struct s_data	*data;
}				t_hero;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_dist
{
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		x;
	int		y;
}				t_dist;

typedef struct	s_data {
	void	*mlx;
	void	*win;

	t_img	*mandat;
	t_hero	*hero;

	int		key_w;
	int		key_s;
	int		key_d;
	int		key_a;
	int		key_arrow_l;
	int		key_arrow_r;

	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	old_time;

	int	mapX;
	int	mapY;

	int	**map;
}				t_data;

int	graphic(void);
int	closer(t_data *data);
int	key_hook(int keycode, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_release(int key, t_data *data);
int		key_press(int key, t_data *data);
void	move_hero(t_data *data);

#endif